# 7주차 2차시

> 수업 날짜: `2026-10-14`

## 실습 기록

- 환경: `Ubuntu WSL`
- 실습 위치: 홈 디렉터리와 `~/fs-lab`
- 자료: 「7장 실습문제.pdf」, `history.txt`
- 긴 출력은 중간 생략 줄 수를 표시했다. 명령어와 결과는 제공된 실행 기록을 기준으로 정리했다.

### 실습 1. 파일 시스템과 홈 디렉터리 사용량 확인

#### 실행한 명령어와 결과

```console
$ df -h
Filesystem      Size  Used Avail Use% Mounted on
none            7.7G     0  7.7G   0% /usr/lib/modules/6.18.33.2-microsoft-standard-WSL2
none            7.7G  4.0K  7.7G   1% /mnt/wsl
drivers         920G  348G  573G  38% /usr/lib/wsl/drivers
/dev/sdd       1007G  3.5G  953G   1% /
none            7.7G   36K  7.7G   1% /mnt/wslg
none            7.7G     0  7.7G   0% /usr/lib/wsl/lib
rootfs          7.7G  2.8M  7.7G   1% /init
none            7.7G  544K  7.7G   1% /run
none            7.7G     0  7.7G   0% /run/lock
none            7.7G     0  7.7G   0% /run/shm
none            7.7G   80K  7.7G   1% /mnt/wslg/versions.txt
none            7.7G   80K  7.7G   1% /mnt/wslg/doc
C:\             920G  348G  573G  38% /mnt/c
none            1.0M     0  1.0M   0% /run/credentials/systemd-journald.service
tmpfs           7.7G     0  7.7G   0% /tmp
none            1.0M     0  1.0M   0% /run/credentials/systemd-resolved.service
none            1.0M     0  1.0M   0% /run/credentials/getty@tty1.service
tmpfs           1.6G   12K  1.6G   1% /run/user/1000
$ df -hT /
Filesystem     Type  Size  Used Avail Use% Mounted on
/dev/sdd       ext4 1007G  3.5G  953G   1% /
$ du -sh ~
709M    /home/user
```

`df -h`는 파일 시스템 전체의 용량과 사용량을, `du -sh ~`는 홈 디렉터리 아래 파일과 디렉터리의 디스크 사용량을 보여 준다. 루트 파일 시스템은 `/dev/sdd`의 `ext4`였으며 전체 `1007G`, 사용 `3.5G`, 여유 `953G`, 사용률 `1%`로 나타났다. 홈 디렉터리의 사용량은 `709M`이었다.

---

### 실습 2. findmnt로 마운트 관계 확인

#### 실행한 명령어와 결과

```console
$ findmnt
TARGET         SOURCE FSTYPE  OPTIONS
/              /dev/sdd
│                     ext4    rw,relatime,discard,errors=remount-ro,data
├─/usr/lib/modules/6.18.33.2-microsoft-standard-WSL2
│              none   overlay rw,nosuid,nodev,noatime,lowerdir=/modules,
├─/mnt/wsl     none   tmpfs   rw,relatime
├─/usr/lib/wsl/drivers
│              drivers
│                     9p      ro,nosuid,nodev,noatime,aname=drivers;fmas
├─/mnt/wslg    none   tmpfs   rw,relatime
│ ├─/mnt/wslg/distro
│ │            /dev/sdd
[... 중간 출력 61줄 생략 ...]
  └─/tmp/.X11-unix
               none[/.X11-unix]
                      tmpfs   ro,relatime
```

`findmnt`는 파일 시스템이 연결된 위치를 트리로 보여 준다. `TARGET`은 마운트 지점, `SOURCE`는 원본 장치나 파일 시스템, `FSTYPE`은 파일 시스템 종류이다. `/dev/sdd`는 `/`에, Windows의 `C:\`는 `/mnt/c`에 연결되어 있었다. 마운트 지점은 해당 파일 시스템에 접근하는 디렉터리이다.

---

### 실습 3. 파일 이름 변경과 i-노드 확인

#### 실행한 명령어와 결과

```console
$ mkdir -p ~/fs-lab
$ cd ~/fs-lab
$ echo "Hello Linux" > test.txt
$ ls -i test.txt
42016 test.txt
$ stat test.txt
  File: test.txt
  size: 12              Blocks: 8          IO Block: 4096   regular file
Device: 8,48    Inode: 42016       Links: 1
Access: (0644/-rw-r--r--)  Uid: ( 1000/    user)   Gid: ( 1000/    user)
Access: 2026-10-14 16:10:49.745736452 +0900
Modify: 2026-10-14 16:10:49.745736452 +0900
Change: 2026-10-14 16:10:49.745736452 +0900
 Birth: 2026-10-14 16:10:49.745736452 +0900
$ mv test.txt sample.txt
$ ls -i sample.txt
42016 sample.txt
```

`test.txt`의 크기는 `12`바이트, 권한은 `0644`, 링크 수는 `1`, i-노드 번호는 `42016`이었다. `mv`로 같은 디렉터리 안에서 이름을 `sample.txt`로 바꿔도 i-노드 번호는 유지되었다. 파일 이름은 디렉터리 엔트리에 저장되므로, 이번 이름 변경은 같은 i-노드를 가리키는 이름을 바꾼 것이다. `stat`에는 접근·수정·상태 변경·생성 시간도 함께 출력되었다.

---

### 실습 4. 하드 링크와 심볼릭 링크 비교

#### 실행한 명령어와 결과

```console
$ ln sample.txt hard.txt
$ ln -s sample.txt symbolic.txt
ln: Already exists
$ ls -li sample.txt hard.txt symbolic.txt
42016 -rw-r--r-- 2 user user 12 Oct 14 16:10 hard.txt
42016 -rw-r--r-- 2 user user 12 Oct 14 16:10 sample.txt
49650 lrwxrwxrwx 1 user user 10 Oct 13 22:19 symbolic.txt -> sample.txt
```

`hard.txt`와 `sample.txt`는 같은 i-노드 `42016`을 가리켰고 링크 수는 모두 `2`였다. `symbolic.txt`는 별도의 i-노드 `49650`을 갖고 `sample.txt`를 가리켰으며 링크 수는 `1`이었다. 하드 링크는 같은 파일의 i-노드를 공유하고, 심볼릭 링크는 대상 경로를 담는 별도 파일이다.

`ln -s` 실행에서는 `ln: Already exists`가 출력되었다. 이후 조회에 표시된 `symbolic.txt`의 시간은 `Oct 13 22:19`이므로, 이번 명령으로 새로 생성한 링크가 아니라 이미 있던 링크를 확인한 결과이다.

---

### 실습 5. 디렉터리와 점 항목의 i-노드 확인

#### 실행한 명령어와 결과

```console
$ mkdir dir1
$ touch dir1/a.txt dir1/b.txt
$ ls -id dir1
48866 dir1
$ ls -ia dir1
48866 .  42075 ..  49602 a.txt  49682 b.txt
$ stat dir1
  File: dir1
  size: 4096            Blocks: 8          IO Block: 4096   directory
Device: 8,48    Inode: 48866       Links: 2
Access: (0755/drwxr-xr-x)  Uid: ( 1000/    user)   Gid: ( 1000/    user)
Access: 2026-10-14 16:11:51.393732301 +0900
Modify: 2026-10-14 16:11:45.685732560 +0900
Change: 2026-10-14 16:11:45.685732560 +0900
 Birth: 2026-10-14 16:11:42.713732724 +0900
$ ls -ia dir1
48866 .  42075 ..  49602 a.txt  49682 b.txt
$ ls -id dir1/.
48866 dir1/.
$ ls -id dir1/..
42075 dir1/..
$ ls -id .
42075 .
```

`dir1`의 i-노드 번호는 `48866`, 그 안의 `a.txt`와 `b.txt`는 각각 `49602`, `49682`였다. 디렉터리와 내부 파일은 각각 별도의 i-노드를 갖는다. `dir1/.`은 `dir1` 자신을 가리켜 `48866`, `dir1/..`는 부모인 `fs-lab`을 가리켜 `42075`로 나타났다. 현재 디렉터리를 조회한 `ls -id .`의 결과도 `42075`였다. `stat dir1`에서는 권한 `0755`, 링크 수 `2`, 크기 `4096`바이트를 확인했다.

---

### 실습 6. 파일 크기와 할당된 디스크 공간 비교

#### 실행한 명령어와 결과

```console
$ cd ~/fs-lab
$ dd if=/dev/zero of=file1.dat bs=1K count=1
1+0 records in
1+0 records out
1024 bytes (1.0 kB, 1.0 KiB) copied, 0.000310897 s, 1.0 MB/s
$ dd if=/dev/zero of=file2.dat bs=1K count=4
4+0 records in
4+0 records out
4096 bytes (4.1 kB, 4.0 KiB) copied, 0.000108808 s, 4.1 MB/s
$ dd if=/dev/zero of=file3.dat bs=1K count=52
52+0 records in
52+0 records out
53248 bytes (53 kB, 52 KiB) copied, 0.000256142 s, 53 MB/s
$ ls -l file*.dat
-rw-r--r-- 1 user user  1024 Oct 14 16:12 file1.dat
-rw-r--r-- 1 user user  4096 Oct 14 16:12 file2.dat
-rw-r--r-- 1 user user 53248 Oct 14 16:12 file3.dat
$ stat file1.dat file2.dat file3.dat
  File: file1.dat
  size: 1024            Blocks: 8          IO Block: 4096   regular file
Device: 8,48    Inode: 49683       Links: 1
Access: (0644/-rw-r--r--)  Uid: ( 1000/    user)   Gid: ( 1000/    user)
Access: 2026-10-14 16:12:18.545733542 +0900
Modify: 2026-10-14 16:12:18.547952206 +0900
Change: 2026-10-14 16:12:18.547952206 +0900
 Birth: 2026-10-14 16:12:18.545733542 +0900
  File: file2.dat
  size: 4096            Blocks: 8          IO Block: 4096   regular file
Device: 8,48    Inode: 49688       Links: 1
Access: (0644/-rw-r--r--)  Uid: ( 1000/    user)   Gid: ( 1000/    user)
Access: 2026-10-14 16:12:29.749734457 +0900
Modify: 2026-10-14 16:12:29.751473073 +0900
Change: 2026-10-14 16:12:29.751473073 +0900
 Birth: 2026-10-14 16:12:29.749734457 +0900
  File: file3.dat
  size: 53248           Blocks: 104        IO Block: 4096   regular file
Device: 8,48    Inode: 49695       Links: 1
Access: (0644/-rw-r--r--)  Uid: ( 1000/    user)   Gid: ( 1000/    user)
Access: 2026-10-14 16:12:33.201734328 +0900
Modify: 2026-10-14 16:12:33.206288316 +0900
Change: 2026-10-14 16:12:33.206288316 +0900
 Birth: 2026-10-14 16:12:33.201734328 +0900
$ du -h file*.dat
4.0K    file1.dat
4.0K    file2.dat
52K     file3.dat
```

`dd`로 만든 파일의 논리적 크기는 각각 `1024`, `4096`, `53248`바이트였다. `du -h` 결과는 `4.0K`, `4.0K`, `52K`였으며, 1KiB 파일도 디스크 공간은 4KiB를 사용했다. 파일 시스템이 블록 단위로 공간을 할당하므로 논리적 크기와 실제 할당량이 다를 수 있다.

`stat`의 `Blocks`는 이 기록에서 512바이트 단위로 해석할 수 있다. `8 × 512 = 4096`바이트, `104 × 512 = 53248`바이트로 `du` 결과와 일치한다. 블록 크기를 4KiB로 가정하면 52KiB 파일에 필요한 데이터 블록은 `52 ÷ 4 = 13`개이다. `IO Block: 4096`과 `Blocks`의 개수는 서로 다른 항목이다.

---

### 실습 7. 이름과 종류로 파일 검색

#### 실행한 명령어와 결과

```console
$ find ~ -type f -name "*.txt"
/home/user/fs-lab/hard.txt
/home/user/fs-lab/sample.txt
/home/user/fs-lab/dir1/b.txt
/home/user/fs-lab/dir1/a.txt
/home/user/cron_test.txt
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/node_modules/@vscode/vscode-languagedetection/dist/lib/979.js.LICENSE.txt
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/node_modules/@vscode/vscode-languagedetection/dist/lib/index.js.LICENSE.txt
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/node_modules/@vscode/deviceid/NOTICE.txt
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/node_modules/@vscode/deviceid/LICENSE.txt
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/node_modules/@vscode/deviceid/owners.txt
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/node_modules/@vscode/iconv-lite-umd/lib/iconv-lite-umd.js.LICENSE.txt
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/node_modules/tas-client/LICENSE.txt
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/node_modules/vscode-jsonrpc/thirdpartynotices.txt
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/node_modules/vscode-jsonrpc/License.txt
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/node_modules/vscode-oniguruma/LICENSE.txt
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/node_modules/vscode-oniguruma/NOTICES.txt
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/extensions/copilot/LICENSE.txt
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/extensions/copilot/ThirdPartyNotices.txt
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/extensions/copilot/node_modules/@github/copilot/shims.txt
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/extensions/terminal-suggest/ThirdPartyNotices.txt
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/extensions/ms-vscode.js-debug/LICENSE.txt
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/extensions/ms-vscode.js-debug/ThirdPartyNotices.txt
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/extensions/ms-vscode.js-debug-companion/LICENSE.txt
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/extensions/ms-vscode.js-debug-companion/ThirdPartyNotices.txt
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/extensions/TypeScriptTeam.jsts-chat-features/LICENSE.txt
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/extensions/ms-vscode.vscode-js-profile-table/ThirdPartyNotices.txt
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/extensions/mermaid-markdown-features/ThirdPartyNotices.txt
/home/user/.vscode-server/extensions/ms-ceintl.vscode-language-pack-ko-1.131.2026090407/ThirdPartyNotices.txt
$ find ~ -type d
/home/user
/home/user/.config
/home/user/.config/ubuntu-insights
/home/user/fs-lab
/home/user/fs-lab/dir1
/home/user/.local
/home/user/.local/share
/home/user/.local/share/nano
/home/user/linux
/home/user/.copilot
/home/user/.copilot/logs
/home/user/.copilot/ide
[... 중간 출력 713줄 생략 ...]
/home/user/.dotnet/corefx
/home/user/.dotnet/corefx/cryptography
/home/user/.dotnet/corefx/cryptography/crls
```

`find ~ -type f -name "*.txt"`로 홈 디렉터리 아래 `.txt` 일반 파일을 찾고, `find ~ -type d`로 디렉터리만 검색했다. 일반 파일 검색에는 `sample.txt`, `hard.txt`, `dir1`의 두 파일 등이 포함되었으며, 디렉터리 검색에는 숨김 디렉터리와 그 하위 디렉터리도 포함되었다. `-type f` 조건에는 심볼릭 링크 자체가 포함되지 않는다.

실습문제의 심볼릭 링크 검색·상세 출력 항목은 제공된 실행 기록에서 확인되지 않았다.

---

### 실습 8. 크기·수정 시간과 -exec로 검색

#### 실행한 명령어와 결과

```console
$ du -h file*.dat
4.0K    file1.dat
4.0K    file2.dat
52K     file3.dat
$ find ~ -type f -size +1M
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/out/server-main.js
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/out/vs/workbench/api/node/extensionHostProcess.js
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/out/vs/platform/agentHost/node/agentHostMain.js
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/node_modules/@vscode/sqlite3/build/Release/vscode-sqlite3.node
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/node_modules/@vscode/ripgrep-universal/bin/linux-x64/rg
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/node_modules/@vscode/vsce-sign/bin/vsce-sign
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/node_modules/@vscode/tree-sitter-wasm/wasm/tree-sitter-bash.wasm
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/node_modules/@vscode/tree-sitter-wasm/wasm/tree-sitter-typescript.wasm
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/node_modules/@microsoft/mxc-sdk/bin/x64/wxc-exec.exe
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/node_modules/@microsoft/mxc-sdk/bin/x64/unix-test-proxy
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/node_modules/@microsoft/mxc-sdk/bin/x64/wxc-wslc-daemon.exe
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/node_modules/@microsoft/mxc-sdk/bin/x64/wslcsdk.dll
[... 중간 출력 52줄 생략 ...]
/home/user/.vscode-server/bin/a44adf7f53e00964ab890f9f8758a334f1fc15bc/node
/home/user/.vscode-server/extensions/ms-ceintl.vscode-language-pack-ko-1.131.2026090407/translations/main.i18n.json
/home/user/.vscode-server/data/CachedProfilesData/__default__profile__/extensions.builtin.cache
$ find ~ -type f -mtime -7
/home/user/fs-lab/file3.dat
/home/user/fs-lab/hard.txt
/home/user/fs-lab/sample.txt
/home/user/fs-lab/file2.dat
/home/user/fs-lab/file1.dat
/home/user/fs-lab/dir1/b.txt
/home/user/fs-lab/dir1/a.txt
/home/user/cron_test.txt
/home/user/nohup.out
/home/user/.motd_shown
/home/user/.lesshst
/home/user/.cache/ubuntu-insights/linux/local/1791896886.json
/home/user/.cache/ubuntu-pro/ubuntu-pro.log
/home/user/.selected_editor
/home/user/.bash_history
$ find ~/fs-lab -type f -name "*.txt" -exec ls -l {} \;
-rw-r--r-- 2 user user 12 Oct 14 16:10 /home/user/fs-lab/hard.txt
-rw-r--r-- 2 user user 12 Oct 14 16:10 /home/user/fs-lab/sample.txt
-rw-r--r-- 1 user user 0 Oct 14 16:11 /home/user/fs-lab/dir1/b.txt
-rw-r--r-- 1 user user 0 Oct 14 16:11 /home/user/fs-lab/dir1/a.txt
```

`du -h file*.dat`를 다시 실행한 결과도 `4.0K`, `4.0K`, `52K`였다. `find ~ -type f -size +1M`으로 1MiB보다 큰 일반 파일을 검색했고, `-mtime -7`로 24시간 단위 경과 시간에 따라 최근 7일 이내에 수정된 일반 파일을 검색했다.

`-exec ls -l {} \;`는 검색된 각 경로를 `{}`에 넣어 상세 정보를 출력한다. 이 기록에서는 `hard.txt`, `sample.txt`, `dir1/b.txt`, `dir1/a.txt` 네 항목이 출력되었다.

---

### 실습 9. grep으로 문자열 검색과 줄 수 확인

#### 실행한 명령어와 결과

```console
$ grep "tcp" /etc/services
tcpmux          1/tcp                           # TCP port service multiplexer
echo            7/tcp
discard         9/tcp           sink null
systat          11/tcp          users
daytime         13/tcp
netstat         15/tcp
qotd            17/tcp          quote
chargen         19/tcp          ttytst source
ftp-data        20/tcp
ftp             21/tcp
ssh             22/tcp                          # SSH Remote Login Protocol
telnet          23/tcp
[... 중간 출력 205줄 생략 ...]
dircproxy       57000/tcp                       # Detachable IRC Proxy
tfido           60177/tcp                       # fidonet EMSI over telnet
fido            60179/tcp                       # fidonet EMSI over TCP
$ grep -c "tcp" /etc/services
220
$ grep "bash" /etc/passwd
root:x:0:0:root:/root:/bin/bash
user:x:1000:1000::/home/user:/bin/bash
```

`grep "tcp" /etc/services`는 `tcp`가 포함된 줄을 출력했고, `grep -c`는 일치한 줄 수 `220`을 출력했다. 이는 문자열의 총 등장 횟수가 아니라 일치하는 줄의 개수이다. `/etc/passwd`에서 `bash`를 검색한 결과에는 `root`와 `user` 계정이 나타났다.

---

### 실습 10. 제외 조건과 줄 시작 조건으로 검색

#### 실행한 명령어와 결과

```console
$ grep -v "nologin" /etc/passwd
root:x:0:0:root:/root:/bin/bash
sync:x:4:65534:sync:/bin:/bin/sync
dhcpcd:x:996:996:DHCP Client Daemon:/usr/lib/dhcpcd:/bin/false
user:x:1000:1000::/home/user:/bin/bash
$ grep "^root" /etc/passwd
root:x:0:0:root:/root:/bin/bash
```

`grep -v "nologin"`은 `nologin`이 없는 줄을 출력하여 `root`, `sync`, `dhcpcd`, `user` 계정이 나타났다. 이 조건만으로 모든 계정의 대화형 로그인이 가능하다고 판단할 수는 없다. `grep "^root"`의 `^`는 줄의 시작을 뜻하며, 결과에는 `root` 계정 한 줄이 출력되었다.

---

### 실습 11. 파이프로 프로세스와 소유 항목 검색

#### 실행한 명령어와 결과

```console
$ ps -ef | awk '$1 == "root"'
root           1       0  0 16:09 ?        00:00:00 /sbin/init
root           2       1  0 16:09 hvc0     00:00:00 /init
root           6       2  0 16:09 hvc0     00:00:00 plan9 --control-socket 7 --log-level 4 --server-fd 8 --pipe-fd 10 --log-truncate
root          46       1  0 16:09 ?        00:00:00 /usr/lib/systemd/systemd-journald
root          84       1  0 16:09 ?        00:00:00 /usr/lib/systemd/systemd-udevd
root         157       1  0 16:09 ?        00:00:00 /bin/sh /usr/lib/systemd/scripts/chronyd-starter.sh -n -F 1
root         158       1  0 16:09 ?        00:00:00 /usr/sbin/cron -f -P
root         179       1  0 16:09 ?        00:00:00 /usr/bin/python3 /usr/bin/networkd-dispatcher --run-startup-triggers
root         187       1  0 16:09 ?        00:00:00 /usr/lib/systemd/systemd-logind
root         192       1  0 16:09 ?        00:00:00 /usr/libexec/wsl-pro-service
root         219       1  0 16:09 tty1     00:00:00 /usr/sbin/agetty --noreset --noclear --issue-file=/etc/issue:/etc/issue.d:/run/issue.d:/usr/lib/issue.d - linux
root         246       1  0 16:09 ?        00:00:00 /usr/bin/python3 /usr/share/unattended-upgrades/unattended-upgrade-shutdown --wait-for-signal
root         340       2  0 16:09 ?        00:00:00 login -- user
root         470       2  0 16:09 ?        00:00:00 /init
root         471     470  0 16:09 ?        00:00:00 /init
root         667      84  0 16:14 ?        00:00:00 (udev-worker)
root         668      84  0 16:14 ?        00:00:00 (udev-worker)
$ ls -l | grep "$(whoami)"
drwxr-xr-x 2 user user  4096 Oct 14 16:11 dir1
-rw-r--r-- 1 user user  1024 Oct 14 16:12 file1.dat
-rw-r--r-- 1 user user  4096 Oct 14 16:12 file2.dat
-rw-r--r-- 1 user user 53248 Oct 14 16:12 file3.dat
-rw-r--r-- 2 user user    12 Oct 14 16:10 hard.txt
-rw-r--r-- 2 user user    12 Oct 14 16:10 sample.txt
lrwxrwxrwx 1 user user    10 Oct 13 22:19 symbolic.txt -> sample.txt
```

`ps -ef`의 출력을 파이프로 `awk`에 전달하고 첫 번째 필드 `$1`이 `root`인 줄만 출력했다. 명령어 부분 등에 포함된 문자열까지 일치하는 것을 피하고 사용자 필드를 기준으로 검색한 것이다.

`ls -l | grep "$(whoami)"`에서는 `whoami`의 결과인 `user`를 포함하는 줄이 출력되었다. 출력된 일곱 항목의 소유자는 모두 `user`였지만, 이 명령은 줄 전체에서 문자열을 검색하므로 소유자 열만 엄밀하게 검사하는 조건은 아니다.

---

### 실습 12. 계정명 오름차순과 내림차순 정렬

#### 실행한 명령어와 결과

```console
$ sort -t: -k1,1 /etc/passwd > user_asc.txt
$ cat user_asc.txt
_apt:x:42:65534::/nonexistent:/usr/sbin/nologin
_chrony:x:988:988:Chrony Daemon:/var/lib/chrony:/usr/sbin/nologin
backup:x:34:34:backup:/var/backups:/usr/sbin/nologin
bin:x:2:2:bin:/bin:/usr/sbin/nologin
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
dhcpcd:x:996:996:DHCP Client Daemon:/usr/lib/dhcpcd:/bin/false
games:x:5:60:games:/usr/games:/usr/sbin/nologin
irc:x:39:39:ircd:/run/ircd:/usr/sbin/nologin
landscape:x:101:103::/var/lib/landscape:/usr/sbin/nologin
list:x:38:38:Mailing List Manager:/var/list:/usr/sbin/nologin
lp:x:7:7:lp:/var/spool/lpd:/usr/sbin/nologin
mail:x:8:8:mail:/var/mail:/usr/sbin/nologin
man:x:6:12:man:/var/cache/man:/usr/sbin/nologin
messagebus:x:995:995:System Message Bus:/nonexistent:/usr/sbin/nologin
news:x:9:9:news:/var/spool/news:/usr/sbin/nologin
nobody:x:65534:65534:nobody:/nonexistent:/usr/sbin/nologin
polkitd:x:987:987:User for polkitd:/:/usr/sbin/nologin
proxy:x:13:13:proxy:/bin:/usr/sbin/nologin
root:x:0:0:root:/root:/bin/bash
sync:x:4:65534:sync:/bin:/bin/sync
sys:x:3:3:sys:/dev:/usr/sbin/nologin
syslog:x:100:101::/nonexistent:/usr/sbin/nologin
systemd-network:x:998:998:systemd Network Management:/:/usr/sbin/nologin
systemd-resolve:x:989:989:systemd Resolver:/:/usr/sbin/nologin
user:x:1000:1000::/home/user:/bin/bash
uucp:x:10:10:uucp:/var/spool/uucp:/usr/sbin/nologin
www-data:x:33:33:www-data:/var/www:/usr/sbin/nologin
$ sort -t: -k1,1r /etc/passwd > user_desc.txt
$ cat user_desc.txt
www-data:x:33:33:www-data:/var/www:/usr/sbin/nologin
uucp:x:10:10:uucp:/var/spool/uucp:/usr/sbin/nologin
user:x:1000:1000::/home/user:/bin/bash
systemd-resolve:x:989:989:systemd Resolver:/:/usr/sbin/nologin
systemd-network:x:998:998:systemd Network Management:/:/usr/sbin/nologin
syslog:x:100:101::/nonexistent:/usr/sbin/nologin
sys:x:3:3:sys:/dev:/usr/sbin/nologin
sync:x:4:65534:sync:/bin:/bin/sync
root:x:0:0:root:/root:/bin/bash
proxy:x:13:13:proxy:/bin:/usr/sbin/nologin
polkitd:x:987:987:User for polkitd:/:/usr/sbin/nologin
nobody:x:65534:65534:nobody:/nonexistent:/usr/sbin/nologin
news:x:9:9:news:/var/spool/news:/usr/sbin/nologin
messagebus:x:995:995:System Message Bus:/nonexistent:/usr/sbin/nologin
man:x:6:12:man:/var/cache/man:/usr/sbin/nologin
mail:x:8:8:mail:/var/mail:/usr/sbin/nologin
lp:x:7:7:lp:/var/spool/lpd:/usr/sbin/nologin
list:x:38:38:Mailing List Manager:/var/list:/usr/sbin/nologin
landscape:x:101:103::/var/lib/landscape:/usr/sbin/nologin
irc:x:39:39:ircd:/run/ircd:/usr/sbin/nologin
games:x:5:60:games:/usr/games:/usr/sbin/nologin
dhcpcd:x:996:996:DHCP Client Daemon:/usr/lib/dhcpcd:/bin/false
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
bin:x:2:2:bin:/bin:/usr/sbin/nologin
backup:x:34:34:backup:/var/backups:/usr/sbin/nologin
_chrony:x:988:988:Chrony Daemon:/var/lib/chrony:/usr/sbin/nologin
_apt:x:42:65534::/nonexistent:/usr/sbin/nologin
```

`-t:`로 필드 구분자를 콜론으로 지정하고 `-k1,1`로 첫 번째 필드인 계정명을 정렬 기준으로 삼았다. 오름차순 결과는 `user_asc.txt`에, `-k1,1r`을 사용한 내림차순 결과는 `user_desc.txt`에 저장했다. `cat`으로 확인한 오름차순의 첫 계정은 `_apt`, 마지막은 `www-data`였으며, 내림차순에서는 순서가 반대였다.

---

### 실습 13. UID의 문자열 정렬과 숫자 정렬 비교

#### 실행한 명령어와 결과

```console
$ sort -t: -k3,3n /etc/passwd > uid_sort.txt
$ cat uid_sort.txt
root:x:0:0:root:/root:/bin/bash
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
bin:x:2:2:bin:/bin:/usr/sbin/nologin
sys:x:3:3:sys:/dev:/usr/sbin/nologin
sync:x:4:65534:sync:/bin:/bin/sync
games:x:5:60:games:/usr/games:/usr/sbin/nologin
man:x:6:12:man:/var/cache/man:/usr/sbin/nologin
lp:x:7:7:lp:/var/spool/lpd:/usr/sbin/nologin
mail:x:8:8:mail:/var/mail:/usr/sbin/nologin
news:x:9:9:news:/var/spool/news:/usr/sbin/nologin
uucp:x:10:10:uucp:/var/spool/uucp:/usr/sbin/nologin
proxy:x:13:13:proxy:/bin:/usr/sbin/nologin
www-data:x:33:33:www-data:/var/www:/usr/sbin/nologin
backup:x:34:34:backup:/var/backups:/usr/sbin/nologin
list:x:38:38:Mailing List Manager:/var/list:/usr/sbin/nologin
irc:x:39:39:ircd:/run/ircd:/usr/sbin/nologin
_apt:x:42:65534::/nonexistent:/usr/sbin/nologin
syslog:x:100:101::/nonexistent:/usr/sbin/nologin
landscape:x:101:103::/var/lib/landscape:/usr/sbin/nologin
polkitd:x:987:987:User for polkitd:/:/usr/sbin/nologin
_chrony:x:988:988:Chrony Daemon:/var/lib/chrony:/usr/sbin/nologin
systemd-resolve:x:989:989:systemd Resolver:/:/usr/sbin/nologin
messagebus:x:995:995:System Message Bus:/nonexistent:/usr/sbin/nologin
dhcpcd:x:996:996:DHCP Client Daemon:/usr/lib/dhcpcd:/bin/false
systemd-network:x:998:998:systemd Network Management:/:/usr/sbin/nologin
user:x:1000:1000::/home/user:/bin/bash
nobody:x:65534:65534:nobody:/nonexistent:/usr/sbin/nologin
$ sort -t: -k3,3 /etc/passwd > uid_lex_sort.txt
$ head -n 20 uid_lex_sort.txt
root:x:0:0:root:/root:/bin/bash
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
uucp:x:10:10:uucp:/var/spool/uucp:/usr/sbin/nologin
syslog:x:100:101::/nonexistent:/usr/sbin/nologin
user:x:1000:1000::/home/user:/bin/bash
landscape:x:101:103::/var/lib/landscape:/usr/sbin/nologin
proxy:x:13:13:proxy:/bin:/usr/sbin/nologin
bin:x:2:2:bin:/bin:/usr/sbin/nologin
sys:x:3:3:sys:/dev:/usr/sbin/nologin
www-data:x:33:33:www-data:/var/www:/usr/sbin/nologin
backup:x:34:34:backup:/var/backups:/usr/sbin/nologin
list:x:38:38:Mailing List Manager:/var/list:/usr/sbin/nologin
irc:x:39:39:ircd:/run/ircd:/usr/sbin/nologin
sync:x:4:65534:sync:/bin:/bin/sync
_apt:x:42:65534::/nonexistent:/usr/sbin/nologin
games:x:5:60:games:/usr/games:/usr/sbin/nologin
man:x:6:12:man:/var/cache/man:/usr/sbin/nologin
nobody:x:65534:65534:nobody:/nonexistent:/usr/sbin/nologin
lp:x:7:7:lp:/var/spool/lpd:/usr/sbin/nologin
mail:x:8:8:mail:/var/mail:/usr/sbin/nologin
$ head -n 20 uid_sort.txt
root:x:0:0:root:/root:/bin/bash
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
bin:x:2:2:bin:/bin:/usr/sbin/nologin
sys:x:3:3:sys:/dev:/usr/sbin/nologin
sync:x:4:65534:sync:/bin:/bin/sync
games:x:5:60:games:/usr/games:/usr/sbin/nologin
man:x:6:12:man:/var/cache/man:/usr/sbin/nologin
lp:x:7:7:lp:/var/spool/lpd:/usr/sbin/nologin
mail:x:8:8:mail:/var/mail:/usr/sbin/nologin
news:x:9:9:news:/var/spool/news:/usr/sbin/nologin
uucp:x:10:10:uucp:/var/spool/uucp:/usr/sbin/nologin
proxy:x:13:13:proxy:/bin:/usr/sbin/nologin
www-data:x:33:33:www-data:/var/www:/usr/sbin/nologin
backup:x:34:34:backup:/var/backups:/usr/sbin/nologin
list:x:38:38:Mailing List Manager:/var/list:/usr/sbin/nologin
irc:x:39:39:ircd:/run/ircd:/usr/sbin/nologin
_apt:x:42:65534::/nonexistent:/usr/sbin/nologin
syslog:x:100:101::/nonexistent:/usr/sbin/nologin
landscape:x:101:103::/var/lib/landscape:/usr/sbin/nologin
polkitd:x:987:987:User for polkitd:/:/usr/sbin/nologin
```

`sort -t: -k3,3n`은 세 번째 필드인 UID만 숫자 기준으로 정렬하며 결과를 `uid_sort.txt`에 저장했다. `-k3,3`을 사용한 문자열 정렬 결과는 `uid_lex_sort.txt`에 저장했다.

문자열 정렬의 앞부분에서는 UID가 `0`, `1`, `10`, `100`, `1000`, `101`, `13`, `2` 순서로 나타났다. 숫자 정렬은 `0`, `1`, `2`, `3`, `4`처럼 실제 수의 크기 순서였다. 두 파일의 앞 20줄을 비교해 차이를 확인했다.

---

### 실습 14. sort와 sort -n의 차이 확인

#### 실행한 명령어와 결과

```console
$ printf "2\n10\n100\n20\n" > numbers.txt
$ sort numbers.txt
10
100
2
20
$ sort -n numbers.txt
2
10
20
100
```

`numbers.txt`에 `2`, `10`, `100`, `20`을 한 줄씩 저장했다. 기본 `sort`는 문자열로 비교하여 `10`, `100`, `2`, `20` 순서로 출력했다. `sort -n`은 숫자 값으로 비교하여 `2`, `10`, `20`, `100` 순서로 출력했다.

---

### 실습 15. cmp와 diff로 파일 비교

#### 실행한 명령어와 결과

```console
$ printf "apple\norange\ngrape\n" > file1.txt
$ printf "apple\nbanana\ngrape\n" > file2.txt
$ cat file1.txt
apple
orange
grape
$ cat file2.txt
apple
banana
grape
$ cmp file1.txt file2.txt
file1.txt file2.txt differ: byte 7, line 2
$ diff file1.txt file2.txt
2c2
< orange
---
> banana
```

두 파일은 첫째 줄 `apple`과 셋째 줄 `grape`가 같고 둘째 줄만 `orange`와 `banana`로 달랐다. `cmp`는 첫 차이가 7번째 바이트, 2번째 줄에 있음을 출력했다. `diff`의 `2c2`는 첫 파일의 2번째 줄을 두 번째 파일의 2번째 줄로 변경해야 한다는 뜻이다. `<`는 첫 파일, `>`는 두 번째 파일의 내용을 나타낸다. `cmp`는 바이트 단위 동일 여부와 첫 차이 위치를 확인할 때, `diff`는 텍스트의 줄별 변경 내용을 확인할 때 적합하다.

---

### 실습 16. diff -u로 문맥과 변경 내용 확인

#### 실행한 명령어와 결과

```console
$ diff -u file1.txt file2.txt
--- file1.txt   2026-10-14 16:15:23.691893055 +0900
+++ file2.txt   2026-10-14 16:15:26.703893978 +0900
@@ -1,3 +1,3 @@
 apple
-orange
+banana
 grape
```

`diff -u`는 파일 정보와 함께 변경된 부분 주변의 문맥을 출력했다. `@@ -1,3 +1,3 @@`는 양쪽 파일에서 1번째 줄부터 3줄을 보여 준다는 뜻이다. 본문에서 공백으로 시작하는 `apple`, `grape`는 공통 줄, `-orange`는 첫 파일에서 제거되는 줄, `+banana`는 두 번째 파일에서 추가되는 줄이다. 맨 위의 `---`, `+++`는 본문 변경 표시가 아니라 비교 대상 파일 정보이다.

---

### 실습 17. mount·findmnt·df로 마운트 상태 비교

#### 실행한 명령어와 결과

```console
$ mount
none on /usr/lib/modules/6.18.33.2-microsoft-standard-WSL2 type overlay (rw,nosuid,nodev,noatime,lowerdir=/modules,upperdir=/lib/modules/6.18.33.2-microsoft-standard-WSL2/rw/upper,workdir=/lib/modules/6.18.33.2-microsoft-standard-WSL2/rw/work,uuid=on)
none on /mnt/wsl type tmpfs (rw,relatime)
drivers on /usr/lib/wsl/drivers type 9p (ro,nosuid,nodev,noatime,aname=drivers;fmask=222;dmask=222,cache=0x5,access=client,msize=65536,trans=fd,rfd=8,wfd=8)
/dev/sdd on / type ext4 (rw,relatime,discard,errors=remount-ro,data=ordered)
none on /mnt/wslg type tmpfs (rw,relatime)
/dev/sdd on /mnt/wslg/distro type ext4 (ro,relatime,discard,errors=remount-ro,data=ordered)
none on /usr/lib/wsl/lib type overlay (rw,nosuid,nodev,noatime,lowerdir=/gpu_lib_packaged:/gpu_lib_inbox,upperdir=/gpu_lib/rw/upper,workdir=/gpu_lib/rw/work,uuid=on)
rootfs on /init type rootfs (ro,size=8019140k,nr_inodes=2004785)
none on /dev type devtmpfs (rw,nosuid,relatime,size=8019140k,nr_inodes=2004785,mode=755)
sysfs on /sys type sysfs (rw,nosuid,nodev,noexec,noatime)
proc on /proc type proc (rw,nosuid,nodev,noexec,noatime)
devpts on /dev/pts type devpts (rw,nosuid,noexec,noatime,gid=5,mode=620,ptmxmode=000)
none on /run type tmpfs (rw,nosuid,nodev,mode=755)
none on /run/lock type tmpfs (rw,nosuid,nodev,noexec,noatime)
none on /run/shm type tmpfs (rw,nosuid,nodev,noatime)
none on /dev/shm type tmpfs (rw,nosuid,nodev,noatime)
none on /run/user type tmpfs (rw,nosuid,nodev,noexec,noatime,mode=755)
binfmt_misc on /proc/sys/fs/binfmt_misc type binfmt_misc (rw,relatime)
cgroup2 on /sys/fs/cgroup type cgroup2 (rw,nosuid,nodev,noexec,relatime,nsdelegate)
none on /mnt/wslg/versions.txt type overlay (rw,relatime,lowerdir=/systemvhd,upperdir=/system/rw/upper,workdir=/system/rw/work,uuid=on)
none on /mnt/wslg/doc type overlay (rw,relatime,lowerdir=/systemvhd,upperdir=/system/rw/upper,workdir=/system/rw/work,uuid=on)
none on /tmp/.X11-unix type tmpfs (ro,relatime)
C:\ on /mnt/c type 9p (rw,noatime,aname=drvfs;path=C:\;uid=1000;gid=1000;symlinkroot=/mnt/,cache=0x5,access=client,msize=65536,trans=fd,rfd=6,wfd=6)
none on /run/user type tmpfs (rw,relatime)
none on /run/credentials/systemd-journald.service type tmpfs (ro,nosuid,nodev,noexec,relatime,nosymfollow,size=1024k,nr_inodes=1024,mode=700,noswap)
tracefs on /sys/kernel/tracing type tracefs (rw,nosuid,nodev,noexec,relatime)
debugfs on /sys/kernel/debug type debugfs (rw,nosuid,nodev,noexec,relatime)
mqueue on /dev/mqueue type mqueue (rw,nosuid,nodev,noexec,relatime)
hugetlbfs on /dev/hugepages type hugetlbfs (rw,nosuid,nodev,relatime,pagesize=2M)
tmpfs on /tmp type tmpfs (rw,nosuid,nodev,nr_inodes=1048576)
configfs on /sys/kernel/config type configfs (rw,nosuid,nodev,noexec,relatime)
fusectl on /sys/fs/fuse/connections type fusectl (rw,nosuid,nodev,noexec,relatime)
none on /run/credentials/systemd-resolved.service type tmpfs (ro,nosuid,nodev,noexec,relatime,nosymfollow,size=1024k,nr_inodes=1024,mode=700,noswap)
none on /tmp/.X11-unix type tmpfs (ro,relatime)
none on /run/credentials/getty@tty1.service type tmpfs (ro,nosuid,nodev,noexec,relatime,nosymfollow,size=1024k,nr_inodes=1024,mode=700,noswap)
tmpfs on /run/user/1000 type tmpfs (rw,nosuid,nodev,relatime,size=1604980k,nr_inodes=401245,mode=700,uid=1000,gid=1000)
tmpfs on /mnt/wslg/run/user/1000 type tmpfs (rw,nosuid,nodev,relatime,size=1604980k,nr_inodes=401245,mode=700,uid=1000,gid=1000)
$ findmnt
TARGET           SOURCE FSTYPE  OPTIONS
/                /dev/sdd
│                       ext4    rw,relatime,discard,errors=remount-ro,data=order
├─/usr/lib/modules/6.18.33.2-microsoft-standard-WSL2
│                none   overlay rw,nosuid,nodev,noatime,lowerdir=/modules,upperd
├─/mnt/wsl       none   tmpfs   rw,relatime
├─/usr/lib/wsl/drivers
│                drivers
│                       9p      ro,nosuid,nodev,noatime,aname=drivers;fmask=222;
├─/mnt/wslg      none   tmpfs   rw,relatime
│ ├─/mnt/wslg/distro
│ │              /dev/sdd
[... 중간 출력 58줄 생략 ...]
  └─/tmp/.X11-unix
                 none[/.X11-unix]
                        tmpfs   ro,relatime
$ df -hT
Filesystem     Type     Size  Used Avail Use% Mounted on
none           overlay  7.7G     0  7.7G   0% /usr/lib/modules/6.18.33.2-microsoft-standard-WSL2
none           tmpfs    7.7G  4.0K  7.7G   1% /mnt/wsl
drivers        9p       920G  348G  573G  38% /usr/lib/wsl/drivers
/dev/sdd       ext4    1007G  3.5G  953G   1% /
none           tmpfs    7.7G   40K  7.7G   1% /mnt/wslg
none           overlay  7.7G     0  7.7G   0% /usr/lib/wsl/lib
rootfs         rootfs   7.7G  2.8M  7.7G   1% /init
none           tmpfs    7.7G  544K  7.7G   1% /run
none           tmpfs    7.7G     0  7.7G   0% /run/lock
none           tmpfs    7.7G     0  7.7G   0% /run/shm
none           overlay  7.7G   80K  7.7G   1% /mnt/wslg/versions.txt
none           overlay  7.7G   80K  7.7G   1% /mnt/wslg/doc
C:\            9p       920G  348G  573G  38% /mnt/c
none           tmpfs    1.0M     0  1.0M   0% /run/credentials/systemd-journald.service
tmpfs          tmpfs    7.7G     0  7.7G   0% /tmp
none           tmpfs    1.0M     0  1.0M   0% /run/credentials/systemd-resolved.service
none           tmpfs    1.0M     0  1.0M   0% /run/credentials/getty@tty1.service
tmpfs          tmpfs    1.6G   12K  1.6G   1% /run/user/1000
```

`mount`는 마운트된 파일 시스템과 옵션을 나열하고, `findmnt`는 마운트 관계를 트리로 보여 주며, `df -hT`는 파일 시스템별 용량과 종류를 함께 보여 준다. `/dev/sdd`가 `/`에 `ext4`로, `C:\`가 `/mnt/c`에 `9p`로 연결된 것을 각 출력에서 확인했다. 이번 기록에는 조회 명령만 있으며 마운트 상태를 변경하는 명령은 없다.

---

### 실습 18. 홈 디렉터리의 하위 사용량 분석

#### 실행한 명령어와 결과

```console
$ baobab
Command 'baobab' not found, but can be installed with:
sudo apt install baobab
$ du -h --max-depth=1 ~
20K     /home/user/.config
100K    /home/user/fs-lab
12K     /home/user/.local
4.0K    /home/user/linux
20K     /home/user/.copilot
84K     /home/user/.cache
708M    /home/user/.vscode-server
268K    /home/user/.dotnet
709M    /home/user
```

`baobab` 실행에서는 명령을 찾을 수 없다는 메시지와 설치 안내가 출력되었다. 설치를 실행한 기록은 없으며, `du -h --max-depth=1 ~`로 홈 디렉터리와 바로 아래 하위 디렉터리의 사용량을 확인했다. 전체 `709M` 중 `.vscode-server`가 `708M`으로 대부분을 차지했고, `fs-lab`은 `100K`였다.

---
