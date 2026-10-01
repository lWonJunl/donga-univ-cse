# 5주차 2차시

> 수업 날짜: `2026-09-30`

## 실습 기록

- 환경: `Ubuntu WSL 26.04 LTS`

### 실습 1. 환경변수 값 확인

#### 실행한 명령어와 결과

```console
$ echo $SHELL
/bin/bash
$ echo $HOME
/home/user
$ echo $PATH
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/usr/lib/wsl/lib:/mnt/c/Program Files/Microsoft/jdk-21.0.11.10-hotspot/bin:/mnt/c/Program Files (x86)/VMware/VMware Workstation/bin/:/mnt/c/Windows/system32:/mnt/c/Windows:/mnt/c/Windows/System32/Wbem:/mnt/c/Windows/System32/WindowsPowerShell/v1.0/:/mnt/c/Windows/System32/OpenSSH/:/mnt/c/Program Files/dotnet/:/mnt/c/Program Files/Git/cmd:/mnt/c/Program Files/PuTTY/:/mnt/c/Program Files/nodejs/:/mnt/c/mingw64/bin:/mnt/c/Users/user/AppData/Local/Programs/Python/Python310/Scripts/:/mnt/c/Users/user/AppData/Local/Programs/Python/Python310/:/mnt/c/Users/user/.local/bin:/mnt/c/Users/user/AppData/Local/Programs/Python/Python314/Scripts/:/mnt/c/Users/user/AppData/Local/Programs/Python/Python314/:/mnt/c/Users/user/AppData/Local/Microsoft/WindowsApps:/mnt/c/Users/user/AppData/Local/Programs/Microsoft VS Code/bin:/mnt/c/Users/user/AppData/Local/Python/bin:/mnt/c/mingw64/bin:/mnt/c/Users/user/AppData/Local/Programs/Ollama:/mnt/c/Users/user/AppData/Roaming/npm:/mnt/c/Program Files/nodejs/
$ echo $TERM
xterm-256color
```

`echo`로 로그인 쉘, 홈 디렉터리, 명령어 검색 경로, 터미널 종류를 확인했다.

---

### 실습 2. 쉘 변수와 환경변수의 서브 쉘 전달 비교

#### 실행한 명령어와 결과

```console
$ MESSAGE=hello
$ echo $MESSAGE
hello
$ bash
$ echo $MESSAGE
$ exit
exit
$ export MESSAGE
$ bash
$ echo $MESSAGE
hello
$ exit
exit
```

`MESSAGE`를 쉘 변수로 설정했을 때는 새 Bash에서 값이 출력되지 않았고, `export MESSAGE` 이후에는 새 Bash에서도 `hello`가 출력되었다.

---

### 실습 3. Bash 시작 파일 수정과 설정 적용 확인

#### 실행한 명령어와 결과

```console
$ echo "alias dir='ls -F'" >> ~/.bashrc
$ echo "echo Welcome to Linux !" >> ~/.bashrc
$ dir
linux/
$ source ~/.bashrc
Welcome to Linux !
$ type dir
dir is aliased to `ls -F'
$ dir
linux/
```

`~/.bashrc`에 `dir` 별칭과 환영 메시지 명령을 추가했다. 새 터미널을 열었을 때 `Welcome to Linux !`가 정상적으로 출력되었고, `dir`은 `linux/`를 출력했다. `source ~/.bashrc`를 실행해 현재 Bash에도 설정을 적용했으며, `type dir`로 별칭 설정을 확인했다.

---

### 실습 4. 전면·후면 작업 실행과 전환

#### 실행한 명령어와 결과

```console
$ sleep 30
^C
$ sleep 30 &
[1] 1244
$ jobs
[1]+  Running                    sleep 30 &
$ fg %1
sleep 30
```

전면 작업 `sleep 30`은 `Ctrl+C`로 중단했다. 후면 실행 후 `jobs`에서 실행 중인 작업을 확인하고, `fg %1`로 전면 작업으로 전환했다.

---

### 실습 5. 표준출력 저장과 추가

#### 실행한 명령어와 결과

```console
$ ls -l > out1.txt
$ cat out1.txt
total 4
drwxr-xr-x 3 user user 4096 Sep 23 16:48 linux
-rw-r--r-- 1 user user    0 Sep 30 16:57 out1.txt
$ date >> out1.txt
$ cat out1.txt
total 4
drwxr-xr-x 3 user user 4096 Sep 23 16:48 linux
-rw-r--r-- 1 user user    0 Sep 30 16:57 out1.txt
Wed Sep 30 16:57:21 KST 2026
```

`ls -l > out1.txt`로 목록을 파일에 저장하고, `date >> out1.txt`로 기존 내용 뒤에 날짜를 추가했다.

---

### 실습 6. 파일을 통한 표준입력 재지정

#### 실행한 명령어와 결과

```console
$ echo "Hello Linux" > input.txt
$ wc < input.txt
  1       2      12
```

`input.txt`를 만든 뒤, `wc < input.txt`로 파일 내용을 표준입력으로 전달했다. 결과는 1줄, 2단어, 12바이트였다.

---

### 실습 7. 표준출력과 표준오류 재지정 비교

#### 실행한 명령어와 결과

```console
$ ls /etc/passwd /notexist
ls: cannot access '/notexist': No such file or directory
/etc/passwd
$ ls /etc/passwd /notexist > out.txt
ls: cannot access '/notexist': No such file or directory
$ cat out.txt
/etc/passwd
$ ls /etc/passwd /notexist 2> err.txt
/etc/passwd
$ cat err.txt
ls: cannot access '/notexist': No such file or directory
```

`>`로 표준출력을 `out.txt`에 저장해도 오류 메시지는 화면에 남았다. `2>`로 표준오류를 `err.txt`에 저장했을 때는 정상 출력이 화면에 나타났다.

---

### 실습 8. 파이프로 명령어 연결하기

#### 실행한 명령어와 결과

```console
$ ls > list.txt
$ sort -r < list.txt
out1.txt
out.txt
list.txt
linux
input.txt
err.txt
$ ls | sort -r
out1.txt
out.txt
list.txt
linux
input.txt
err.txt
$ who | wc -l
0
```

`sort -r < list.txt`와 `ls | sort -r`의 출력이 같았다. 파이프를 사용하면 중간 파일 없이 같은 결과를 얻을 수 있다. `who | wc -l`의 실행 결과는 `0`이었다.

---

### 실습 9. 명령어 순차 실행과 그룹 출력 비교

#### 실행한 명령어와 결과

```console
$ date; pwd; ls
Wed Sep 30 16:59:40 KST 2026
/home/user
err.txt  input.txt  linux  list.txt  out.txt  out1.txt
$ date; pwd; ls > out1.txt
Wed Sep 30 16:59:47 KST 2026
/home/user
$ (date; pwd; ls) > out2.txt
$ cat out1.txt
err.txt
input.txt
linux
list.txt
out.txt
out1.txt
$ cat out2.txt
Wed Sep 30 16:59:56 KST 2026
/home/user
err.txt
input.txt
linux
list.txt
out.txt
out1.txt
out2.txt
```

`date; pwd; ls`가 순서대로 실행되었다. `ls > out1.txt`에서는 `ls` 출력만 저장되었고, `(date; pwd; ls) > out2.txt`에서는 세 명령의 출력이 함께 저장되었다.

---

### 실습 10. 명령어 성공·실패에 따른 조건부 실행

#### 실행한 명령어와 결과

```console
$ ls /etc/passwd && echo 성공
/etc/passwd
성공
$ ls /notexist && echo 성공
ls: cannot access '/notexist': No such file or directory
$ ls /etc/passwd || echo 실패
/etc/passwd
$ ls /notexist || echo 실패
ls: cannot access '/notexist': No such file or directory
실패
```

`&&` 뒤의 `성공`은 첫 명령이 성공했을 때만 출력되었고, `||` 뒤의 `실패`는 첫 명령이 실패했을 때만 출력되었다.

---

### 실습 11. 파일 이름 대치 패턴 확인

#### 실행한 명령어와 결과

```console
$ mkdir wildcard
$ cd wildcard
$ touch a.c ab.c abc.c a.txt b.c b.txt
$ ls *.c
a.c  ab.c  abc.c  b.c
$ ls ?.c
a.c  b.c
$ ls a*
a.c  a.txt  ab.c  abc.c
$ ls [ab].c
a.c  b.c
```

`*.c`, `?.c`, `a*`, `[ab].c`가 각각 다른 파일 이름 목록으로 대치되는 것을 확인했다.

---

### 실습 12. 명령어 대치로 값 출력

#### 실행한 명령어와 결과

```console
$ echo "현재 시간은 $(date)"
현재 시간은 Wed Sep 30 17:01:49 KST 2026
$ echo "현재 디렉터리는 $(pwd)"
현재 디렉터리는 /home/user/wildcard
$ echo "현재 디렉터리의 파일 개수는 $(ls | wc -w)"
현재 디렉터리의 파일 개수는 6
```

명령어 대치로 현재 시간, 현재 디렉터리, 파일 개수를 출력했다. 기록된 파일 개수는 `6`개였다.

---

### 실습 13. 작은따옴표와 큰따옴표의 대치 결과 비교

#### 실행한 명령어와 결과

```console
$ name=Linux
$ echo '$name'
$name
$ echo "$name"
Linux
$ echo '*'
*
$ echo "*"
*
$ echo *
a.c a.txt ab.c abc.c b.c b.txt
```

작은따옴표 안의 `$name`은 그대로 출력되고 큰따옴표 안에서는 `Linux`로 대치되었다. 따옴표로 감싼 `*`는 그대로 출력되었고, 따옴표 없이 실행한 `echo *`에서는 현재 디렉터리의 파일 이름 6개가 출력되었다.

---
