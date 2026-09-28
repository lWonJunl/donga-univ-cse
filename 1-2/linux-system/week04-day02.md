# 4주차 2차시

> 수업 날짜: `2026-09-23`

## 실습 기록

- 환경: `Ubuntu WSL 26.04 LTS`

### 실습 1. 파일 복사/이동

#### 실행한 명령어와 결과

```console
$ mkdir temp1
$ cp /etc/services temp1
$ cd temp1
$ ls
services
$ cd ..
$ cp /etc/passwd temp1
$ mv temp1/passwd temp1/passwd.old
$ ls -l temp1
total 20
-rw-r--r-- 1 user user  1376 Sep 23 16:37 passwd.old
-rw-r--r-- 1 user user 12990 Sep 23 16:36 services
```

`/etc/services`와 `/etc/passwd`를 `temp1` 디렉터리로 복사한 뒤, `passwd` 파일의 이름을 `passwd.old`로 변경했다.

---

### 실습 2. 디렉터리 복사/삭제

#### 실행한 명령어와 결과

```console
$ cp -r temp1 temp2
$ ls -sl
total 8
4 drwxr-xr-x 2 user user 4096 Sep 23 16:38 temp1
4 drwxr-xr-x 2 user user 4096 Sep 23 16:39 temp2
$ rmdir temp1
rmdir: failed to remove 'temp1': Directory not empty
$ rm -ri temp1
rm: descend into directory 'temp1'? y
rm: remove regular file 'temp1/passwd.old'? y
rm: remove regular file 'temp1/services'? y
rm: remove directory 'temp1'? y
$ ls -sl
total 4
4 drwxr-xr-x 2 user user 4096 Sep 23 16:39 temp2
$ rm -r temp2
$ ls -sl
total 0
```

`cp -r`로 `temp1` 디렉터리를 `temp2`로 복사했다. 비어 있지 않은 디렉터리는 `rmdir`로 삭제할 수 없음을 확인하고, `rm -ri`와 `rm -r`로 디렉터리와 내부 파일을 삭제했다.

---

### 실습 3. 하드 링크와 심볼릭 링크 만들기

#### 실행한 명령어와 결과

```console
$ echo "Hello Linux" > test.txt
$ ln test.txt hlink.txt
$ ln -s test.txt slink.txt
$ cp test.txt copy.txt
$ ls -li *.txt
41961 -rw-r--r-- 1 user user 12 Sep 23 16:42 copy.txt
42075 -rw-r--r-- 2 user user 12 Sep 23 16:41 hlink.txt
41957 lrwxrwxrwx 1 user user  8 Sep 23 16:41 slink.txt -> test.txt
42075 -rw-r--r-- 2 user user 12 Sep 23 16:41 test.txt
```

`test.txt`를 만든 뒤 `ln`으로 하드 링크 `hlink.txt`를, `ln -s`로 심볼릭 링크 `slink.txt`를 만들었다. `ls -li`로 하드 링크가 원본 파일과 같은 inode 번호를 사용하는 것을 확인했다.

---

### 실습 4. 하드 링크 파일 내용 변경

#### 실행한 명령어와 결과

```console
$ echo "하드 링크 수정 테스트" > hlink.txt
$ cat test.txt
하드 링크 수정 테스트
```

하드 링크 파일인 `hlink.txt`의 내용을 수정한 뒤, 원본 파일 `test.txt`에도 같은 내용이 반영되는 것을 확인했다.

---

### 실습 5. 원본 파일 삭제 후 링크 상태 확인

#### 실행한 명령어와 결과

```console
$ rm -ri test.txt
rm: remove regular file 'test.txt'? y
$ ls -li *.txt
41961 -rw-r--r-- 1 user user 12 Sep 23 16:42 copy.txt
42075 -rw-r--r-- 1 user user 31 Sep 23 16:43 hlink.txt
41957 lrwxrwxrwx 1 user user  8 Sep 23 16:41 slink.txt -> test.txt
```

원본 파일을 삭제한 뒤에도 하드 링크 `hlink.txt`는 유지되고, 심볼릭 링크 `slink.txt`는 원본을 찾을 수 없는 상태가 되는 것을 확인했다.

---

### 실습 6. 파일 종류와 링크 상태 확인

#### 실행한 명령어와 결과

```console
$ ls -sl
4 -rw-r--r-- 1 user user 12 Sep 23 16:42 copy.txt
4 -rw-r--r-- 1 user user 31 Sep 23 16:43 hlink.txt
0 lrwxrwxrwx 1 user user  8 Sep 23 16:41 slink.txt -> test.txt
$ file copy.txt
copy.txt: ASCII text
$ file hlink.txt
hlink.txt: Unicode text, UTF-8 text
$ file slink.txt
slink.txt: broken symbolic link to test.txt
```

`file` 명령어로 일반 파일의 문자 인코딩과 심볼릭 링크의 연결 상태를 확인했다.

---

### 실습 7. 파일과 디렉터리 접근 권한 변경

#### 실행한 명령어와 결과

```console
$ ls -l
total 8
-rw-r--r-- 1 user user 12 Sep 23 16:42 copy.txt
-rw-r--r-- 1 user user 31 Sep 23 16:43 hlink.txt
lrwxrwxrwx 1 user user  8 Sep 23 16:41 slink.txt -> test.txt
$ echo "테스트" > test.txt
$ ls -l
total 12
-rw-r--r-- 1 user user 12 Sep 23 16:42 copy.txt
-rw-r--r-- 1 user user 31 Sep 23 16:43 hlink.txt
lrwxrwxrwx 1 user user  8 Sep 23 16:41 slink.txt -> test.txt
-rw-r--r-- 1 user user 10 Sep 23 16:47 test.txt
$ chmod go+w test.txt
$ ls -l
total 12
-rw-r--r-- 1 user user 12 Sep 23 16:42 copy.txt
-rw-r--r-- 1 user user 31 Sep 23 16:43 hlink.txt
lrwxrwxrwx 1 user user  8 Sep 23 16:41 slink.txt -> test.txt
-rw-rw-rw- 1 user user 10 Sep 23 16:47 test.txt
$ chmod 644 test.txt
$ ls -l
total 12
-rw-r--r-- 1 user user 12 Sep 23 16:42 copy.txt
-rw-r--r-- 1 user user 31 Sep 23 16:43 hlink.txt
lrwxrwxrwx 1 user user  8 Sep 23 16:41 slink.txt -> test.txt
-rw-r--r-- 1 user user 10 Sep 23 16:47 test.txt
$ chmod 666 test.txt
$ ls -l
total 12
-rw-r--r-- 1 user user 12 Sep 23 16:42 copy.txt
-rw-r--r-- 1 user user 31 Sep 23 16:43 hlink.txt
lrwxrwxrwx 1 user user  8 Sep 23 16:41 slink.txt -> test.txt
-rw-rw-rw- 1 user user 10 Sep 23 16:47 test.txt
$ chmod 400 test.txt
$ ls -l
total 12
-rw-r--r-- 1 user user 12 Sep 23 16:42 copy.txt
-rw-r--r-- 1 user user 31 Sep 23 16:43 hlink.txt
lrwxrwxrwx 1 user user  8 Sep 23 16:41 slink.txt -> test.txt
-r-------- 1 user user 10 Sep 23 16:47 test.txt
$ echo "Linux" >> test.txt
bash: test.txt: Permission denied
$ mkdir testdir
$ chmod 600 testdir
$ cd testdir
bash: cd: testdir: Permission denied
$ ls testdir
$ chmod 300 testdir
$ ls testdir
ls: cannot open directory 'testdir': Permission denied
$ chmod 500 testdir
$ cd testdir
$ touch test.txt
touch: cannot touch 'test.txt': Permission denied
```

`chmod`로 파일의 읽기·쓰기 권한을 변경하고, 권한이 없는 파일에는 내용을 추가할 수 없음을 확인했다. 디렉터리의 권한을 바꾸면서 디렉터리 이동, 목록 확인, 파일 생성에 필요한 권한도 함께 확인했다.

---