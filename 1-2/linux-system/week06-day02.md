# 6주차 2차시

> 수업 날짜: `2026-10-07`

## 실습 기록

- 환경: `Ubuntu WSL 26.04 LTS`

### 실습 1. 프로세스와 부모·자식 관계 확인

#### 실행한 명령어와 결과

```console
$ ps
    PID TTY          TIME CMD
    474 pts/0    00:00:00 bash
    492 pts/0    00:00:00 ps
$ ps -f
UID          PID    PPID  C STIME TTY          TIME CMD
user         474     473  0 22:02 pts/0    00:00:00 bash --rcfile /mnt/c
user         497     474  0 22:03 pts/0    00:00:00 ps -f
$ echo $$
474
$ ps -ef | less
```

`ps`로 현재 터미널의 프로세스를 확인하고, `ps -f`로 사용자와 부모 프로세스 정보까지 확인했다. `PID`는 프로세스 번호, `PPID`는 부모 프로세스 번호, `TTY`는 연결된 터미널, `CMD`는 실행 명령을 나타낸다. `echo $$`의 결과 `474`는 Bash의 PID와 같았고, `ps -f` 프로세스의 PPID도 `474`로 나타났다. `ps -ef | less`의 조회 화면은 기록에 남지 않아, 추가 실행에서는 `ps -ef`로 전체 프로세스를 직접 출력했다.

#### 추가 실행한 명령어와 결과

```console
$ ps -ef
UID          PID    PPID  C STIME TTY          TIME CMD
root           1       0  0 22:02 ?        00:00:00 /sbin/init
root           2       1  0 22:02 hvc0     00:00:00 /init
root           8       2  0 22:02 hvc0     00:00:00 plan9 --control-socket 7 --log-level 4 --server-fd 8 --pipe-fd 10 --
root          48       1  0 22:02 ?        00:00:00 /usr/lib/systemd/systemd-journald
systemd+      80       1  0 22:02 ?        00:00:00 /usr/lib/systemd/systemd-resolved
root          87       1  0 22:02 ?        00:00:02 /usr/lib/systemd/systemd-udevd
root         165       1  0 22:02 ?        00:00:00 /bin/sh /usr/lib/systemd/scripts/chronyd-starter.sh -n -F 1
root         166       1  0 22:02 ?        00:00:00 /usr/sbin/cron -f -P
message+     167       1  0 22:02 ?        00:00:00 @dbus-daemon --system --address=systemd: --nofork --nopidfile --syst
root         180       1  0 22:02 ?        00:00:00 /usr/bin/python3 /usr/bin/networkd-dispatcher --run-startup-triggers
root         189       1  0 22:02 ?        00:00:00 /usr/lib/systemd/systemd-logind
root         222       1  0 22:02 tty1     00:00:00 /usr/sbin/agetty --noreset --noclear --issue-file=/etc/issue:/etc/is
syslog       223       1  0 22:02 ?        00:00:00 /usr/sbin/rsyslogd -n -iNONE
_chrony      239     165  0 22:02 ?        00:00:00 /usr/sbin/chronyd -n -F 1 -x
root         245       1  0 22:02 ?        00:00:00 /usr/bin/python3 /usr/share/unattended-upgrades/unattended-upgrade-s
_chrony      256     239  0 22:02 ?        00:00:00 /usr/sbin/chronyd -n -F 1 -x
root         317       2  0 22:02 ?        00:00:00 login -- user
user         382       1  0 22:02 ?        00:00:00 /usr/lib/systemd/systemd --user
user         385     382  0 22:02 ?        00:00:00 (sd-pam)
user         413     317  0 22:02 pts/1    00:00:00 -bash
root         993       2  0 22:16 ?        00:00:00 /init
root         994     993  0 22:16 ?        00:00:00 /init
user         995     994  0 22:16 pts/2    00:00:00 bash --rcfile /mnt/c/Users/user/Github/linux-terminal-recorder/recor
root        1254       2  0 22:23 ?        00:00:00 /init
root        1255    1254  0 22:23 ?        00:00:00 /init
user        1257    1255  0 22:23 pts/0    00:00:00 -bash
root        1418       1  0 22:27 ?        00:00:00 /init
user        1484    1418  0 22:27 ?        00:00:00 sleep 300
root        1504       2  0 22:28 ?        00:00:00 /init
root        1505    1504  0 22:28 ?        00:00:00 /init
user        1509    1505  0 22:28 pts/3    00:00:00 -bash
user        1581    1509  0 22:28 pts/3    00:00:00 sleep 300
user        1678    1509  0 22:28 pts/3    00:00:00 ps -ef
```

추가 조회에서는 여러 터미널과 시스템 서비스의 프로세스가 함께 출력되었다. `ps -ef`의 PID는 `1678`, PPID는 `1509`였으며, 부모 프로세스는 같은 터미널 `pts/3`의 Bash였다.

---

### 실습 2. 후면 작업과 프로세스 검색

#### 실행한 명령어와 결과

```console
$ sleep 300 &
[1] 515
$ sleep 300 &
[2] 518
$ jobs
[1]-  Running                    sleep 300 &
[2]+  Running                    sleep 300 &
$ ps -f
UID          PID    PPID  C STIME TTY          TIME CMD
user         474     473  0 22:02 pts/0    00:00:00 bash --rcfile /mnt/c
user         515     474  0 22:03 pts/0    00:00:00 sleep 300
user         518     474  0 22:03 pts/0    00:00:00 sleep 300
user         519     474  0 22:03 pts/0    00:00:00 ps -f
$ pgrep sleep
515
518
$ pgrep -l sleep
515 sleep
518 sleep
$ pgrep -n sleep
518
```

`sleep 300`을 두 번 후면 실행했다. 쉘에서 관리하는 작업번호는 `1`, `2`였고, 각 프로세스의 PID는 `515`, `518`이었다. `pgrep sleep`은 PID만, `pgrep -l sleep`은 PID와 프로세스 이름을 출력했다. `pgrep -n sleep`은 검색된 프로세스 중 가장 최근에 시작된 PID `518`을 출력했다.

---

### 실습 3. 전면 실행과 후면 실행 비교

#### 실행한 명령어와 결과

```console
$ sleep 10
$ sleep 10 &
[3] 542
```

`sleep 10`은 전면에서 실행되어 작업이 끝날 때까지 쉘이 기다린다. `sleep 10 &`는 후면에서 실행되어 작업번호 `3`과 PID `542`가 출력되고, 다른 명령을 입력할 수 있다.

---

### 실습 4. 작업 정지와 전면·후면 전환

#### 실행한 명령어와 결과

```console
$ sleep 300
^Z
[4]+  Stopped                    sleep 300
[3]   Done                       sleep 10
$ jobs
[1]   Running                    sleep 300 &
[2]-  Running                    sleep 300 &
[4]+  Stopped                    sleep 300
$ bg %4
[4]+ sleep 300 &
$ jobs
[1]   Running                    sleep 300 &
[2]-  Running                    sleep 300 &
[4]+  Running                    sleep 300 &
$ fg %4
sleep 300
^C
```

전면 실행한 `sleep 300`을 `Ctrl+Z`로 정지하자 작업번호 `4`의 상태가 `Stopped`로 표시되었다. `bg %4`로 후면 실행을 재개한 뒤에는 `Running`으로 바뀌었다. `fg %4`로 전면에 가져온 다음 `Ctrl+C`로 종료했다. 앞서 후면 실행했던 `sleep 10`은 `Done`으로 표시되었다.

---

### 실습 5. 시그널을 이용한 프로세스 제어

#### 실행한 명령어와 결과

```console
$ sleep 300 &
[3] 566
$ jobs -l
[1]    515 Running                    sleep 300 &
[2]-   518 Running                    sleep 300 &
[3]+   566 Running                    sleep 300 &
$ kill -STOP 566
$ kill -CONT 566

[3]+  Stopped                    sleep 300
$ kill -TERM 566
$ jobs
[1]   Running                    sleep 300 &
[2]-  Running                    sleep 300 &
[3]+  Terminated                 sleep 300
$ kill -l
 1) SIGHUP       2) SIGINT       3) SIGQUIT      4) SIGILL       5) SIGTRAP
 6) SIGABRT      7) SIGBUS       8) SIGFPE       9) SIGKILL     10) SIGUSR1
11) SIGSEGV     12) SIGUSR2     13) SIGPIPE     14) SIGALRM     15) SIGTERM
16) SIGSTKFLT   17) SIGCHLD     18) SIGCONT     19) SIGSTOP     20) SIGTSTP
21) SIGTTIN     22) SIGTTOU     23) SIGURG      24) SIGXCPU     25) SIGXFSZ
26) SIGVTALRM   27) SIGPROF     28) SIGWINCH    29) SIGIO       30) SIGPWR
31) SIGSYS      34) SIGRTMIN    35) SIGRTMIN+1  36) SIGRTMIN+2  37) SIGRTMIN+3
38) SIGRTMIN+4  39) SIGRTMIN+5  40) SIGRTMIN+6  41) SIGRTMIN+7  42) SIGRTMIN+8
43) SIGRTMIN+9  44) SIGRTMIN+10 45) SIGRTMIN+11 46) SIGRTMIN+12 47) SIGRTMIN+13
48) SIGRTMIN+14 49) SIGRTMIN+15 50) SIGRTMAX-14 51) SIGRTMAX-13 52) SIGRTMAX-12
53) SIGRTMAX-11 54) SIGRTMAX-10 55) SIGRTMAX-9  56) SIGRTMAX-8  57) SIGRTMAX-7
58) SIGRTMAX-6  59) SIGRTMAX-5  60) SIGRTMAX-4  61) SIGRTMAX-3  62) SIGRTMAX-2
63) SIGRTMAX-1  64) SIGRTMAX
```

`jobs -l`로 작업번호와 PID를 함께 확인하고, PID `566`에 정지·재개·종료 시그널을 보냈다. `SIGSTOP`은 정지, `SIGCONT`는 재개, `SIGTERM`은 종료 요청에 사용한다. 기록에는 `kill -CONT` 입력 뒤에 `Stopped` 알림이 남아 있고, 재개 직후의 `Running` 상태를 조회한 결과는 없다. `kill -TERM` 이후에는 `Terminated`가 표시되었다. `kill -l`로 시그널 목록도 확인했다.

#### 추가 실행한 명령어와 결과

```console
$ sleep 300 &
signal_pid=$!
jobs -l
kill -STOP "$signal_pid"
jobs -l
kill -CONT "$signal_pid"
jobs -l
kill -TERM "$signal_pid"
jobs -l
[2] 1618
[1]-  1581 Running                    nohup sleep 300 &
[2]+  1618 Running                    sleep 300 &
[1]-  1581 Running                    nohup sleep 300 &
[2]+  1618 Stopped (signal)           sleep 300
[1]-  1581 Running                    nohup sleep 300 &
[2]+  1618 Running                    sleep 300 &
[1]-  1581 Running                    nohup sleep 300 &
[2]+  1618 Terminated                 sleep 300
```

추가 실행에서는 `$!`로 직전에 후면 실행한 프로세스의 PID `1618`을 `signal_pid`에 저장했다. 각 시그널을 보낸 뒤 `jobs -l`로 조회하여 `Running` → `Stopped (signal)` → `Running` → `Terminated`로 상태가 바뀌는 것을 확인했다. 함께 표시된 PID `1581`은 별도로 실행한 `nohup` 작업이다.

---

### 실습 6. wait로 후면 작업 종료 기다리기

#### 실행한 명령어와 결과

```console
$ (sleep 5; echo "작업1 종료") &
(sleep 10; echo "작업2 종료") &
echo "기다리기 시작"
wait
echo "모든 작업 종료"
[1] 1283
[2] 1290
기다리기 시작
작업1 종료
[1]-  Done                       ( sleep 5; echo "작업1 종료" )
작업2 종료
[2]+  Done                       ( sleep 10; echo "작업2 종료" )
모든 작업 종료
```

두 작업을 후면에서 실행하고 `wait`로 종료를 기다렸다. 작업번호는 `1`, `2`, PID는 각각 `1283`, `1290`이었다. `기다리기 시작` 다음에 `작업1 종료`, `작업2 종료`가 출력되고, 두 작업이 모두 `Done`으로 표시된 뒤 `모든 작업 종료`가 출력되었다. `wait` 자체는 메시지를 출력하지 않고 후면 작업이 끝날 때까지 기다렸다.

#### wait를 제외하고 실행한 명령어와 결과

```console
$ (sleep 5; echo "작업1 종료") &
(sleep 10; echo "작업2 종료") &
echo "기다리기 시작"
echo "모든 작업 종료"
[1] 1537
[2] 1544
기다리기 시작
모든 작업 종료
작업1 종료
작업2 종료

[1]-  Done                       ( sleep 5; echo "작업1 종료" )
[2]+  Done                       ( sleep 10; echo "작업2 종료" )
```

`wait`를 제외하자 `기다리기 시작` 직후에 `모든 작업 종료`가 출력되었다. 이후 후면 작업이 끝나면서 `작업1 종료`, `작업2 종료`가 출력되었다. `wait`가 있을 때와 달리, 마지막 `echo`는 두 작업의 종료를 기다리지 않고 실행되었다.

---

### 실습 7. nohup으로 후면 작업 실행하기

#### 실행한 명령어와 결과

```console
$ nohup sleep 300 &
[1] 1581
nohup: ignoring input and appending output to 'nohup.out'
$ jobs -l
[1]+  1581 Running                    nohup sleep 300 &
```

`nohup sleep 300 &`로 실행한 작업의 PID는 `1581`이었고, `jobs -l`에서 `Running` 상태를 확인했다. 안내 문구는 표준입력을 무시하고 출력을 `nohup.out`에 추가한다는 뜻이다. `&`는 후면 실행을 담당하고, `nohup`은 터미널 종료 시 전달되는 `SIGHUP`을 무시하도록 실행한다. 이번 기록에서는 실행 상태까지 확인했으며, 터미널 종료 후에도 작업이 유지되는지는 별도로 확인하지 않았다.

---

### 실습 8. 사용자 ID와 SetUID 권한 확인

#### 실행한 명령어와 결과

```console
$ id
uid=1000(user) gid=1000(user) groups=1000(user),4(adm),24(cdrom),27(sudo),30(dip),46(plugdev),100(users)
$ echo $UID
1000
$ echo $EUID
1000
$ ls -l /usr/bin/passwd
-rwsr-xr-x 1 root root 93640 Feb  3  2026 /usr/bin/passwd
```

`id`로 사용자와 소속 그룹을 확인했다. 현재 쉘의 UID와 EUID는 모두 `1000`이었다. `/usr/bin/passwd`는 소유자가 `root`이고, 소유자 실행 권한 위치에 `s`가 표시되어 SetUID가 설정되어 있음을 확인했다.

---

### 실습 9. nice 값과 프로세스 우선순위 확인

#### 실행한 명령어와 결과

```console
$ nice
0
$ nice -n 10 sleep 300 &
[1] 780
$ ps -l
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
4 S  1000     474     473  0  80   0 -  1684 do_wai pts/0    00:00:00 bash
0 S  1000     780     474  0  90  10 -  4028 hrtime pts/0    00:00:00 sleep
0 R  1000     783     474  0  80   0 -  1798 -      pts/0    00:00:00 ps
$ jobs
[1]+  Running                    nice -n 10 sleep 300 &
```

`nice`로 확인한 현재 nice 값은 `0`이었다. `nice -n 10 sleep 300 &`로 실행한 프로세스의 PID는 `780`이고, `ps -l`에서 `NI` 값은 `10`, `PRI` 값은 `90`으로 표시되었다. nice 값이 커지면 CPU 스케줄링 우선순위는 낮아진다. `jobs`에서도 해당 작업이 후면에서 실행 중임을 확인했다.

---
