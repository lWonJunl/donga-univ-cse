# 12주차 2차시

## 실습 기록

- 환경: `Ubuntu WSL 26.04 LTS`

### 실습 1. APT 패키지 관리

```console
$ command -v tree
$ apt search tree
$ apt show tree
$ sudo apt update
$ sudo apt install tree
$ tree --version
$ tree .
$ sudo apt remove tree
$ command -v tree
```

`apt update`는 저장소의 패키지 목록을 갱신하고 `apt install`은 패키지와 필요한 의존성을 설치한다. `apt show`에서는 버전과 설명 등을 확인할 수 있다. 설치 전과 제거 후 `command -v tree`는 경로를 출력하지 않았다. 이후 다음 실습을 위해 `tree`를 다시 설치했다.

---

### 실습 2. dpkg로 패키지 조사

```console
$ dpkg -l bash
ii  bash  5.3-2ubuntu1  amd64  GNU Bourne Again SHell
$ dpkg -s bash
Status: install ok installed
Version: 5.3-2ubuntu1
$ dpkg -L bash
$ dpkg -S /usr/bin/bash
bash: /usr/bin/bash
```

`ii`는 설치가 요청되었고 현재 설치된 상태를 뜻한다. `-L`은 패키지가 설치한 파일을 나열하고 `-S`는 해당 경로를 소유한 패키지를 찾는다. APT는 저장소와 의존성을 이용한 설치에 적합하고, dpkg는 로컬 패키지 상태와 파일을 조사할 수 있다.

---

### 실습 3. tar 아카이브 생성과 복원

```console
$ mkdir -p ~/chap09/data/sub
$ printf "alpha\n" > ~/chap09/data/a.txt
$ printf "beta\n" > ~/chap09/data/b.txt
$ printf "gamma\n" > ~/chap09/data/sub/c.txt
$ cd ~/chap09
$ tar -cvf data.tar data/
$ tar -tvf data.tar
$ mkdir -p restore
$ tar -xvf data.tar -C restore
$ tree data restore
```

`-c`는 아카이브를 만들고 `-x`는 추출한다. `-v`는 처리한 항목을 표시하고 `-f`는 아카이브 파일을 지정한다. 복원한 디렉터리에서 `data/sub/c.txt`를 포함한 구조를 확인했다. 이 tar 명령은 파일을 묶지만 압축하지 않는다.

---

### 실습 4. 압축 형식 비교

```console
$ tar -czf data.tar.gz data/
$ tar -cjf data.tar.bz2 data/
$ tar -cJf data.tar.xz data/
$ ls -lh data.tar data.tar.gz data.tar.bz2 data.tar.xz
data.tar      10K
data.tar.gz   221
data.tar.bz2  225
data.tar.xz   264
$ tar -tzf data.tar.gz
$ mkdir -p restore-gz
$ tar -xzf data.tar.gz -C restore-gz
$ tree restore-gz
```

처음 bzip2 명령이 실패하여 `bzip2`와 `xz-utils`를 설치한 뒤 다시 실행했다. `-z`, `-j`, `-J`는 각각 gzip, bzip2, xz를 사용한다. 이 작은 실습 데이터에서는 gzip 결과가 가장 작았다. `.tar.gz`는 tar로 묶은 데이터를 gzip으로 압축한 파일이다.

---

### 실습 5. GCC 다중 모듈 컴파일

```console
$ gcc -c main.c
$ gcc -c calc.c
$ gcc main.o calc.o -o program
$ ./program
30
$ nano calc.c
$ gcc -c calc.c
$ gcc main.o calc.o -o program
$ ./program
200
```

처음 `gcc`가 없어 설치한 뒤 컴파일했다. `-c`는 링크하지 않고 목적 파일을 만든다. `calc.c`의 덧셈을 곱셈으로 바꾼 뒤 해당 파일만 재컴파일하고 기존 `main.o`와 다시 링크했다. 선언과 `main.c`가 바뀌지 않았으므로 `main.o`는 재사용할 수 있었다. 소스는 편집기로 작성해 실행 기록에 전체 내용이 남아 있지 않다.

---

### 실습 6. Makefile 자동 빌드

```console
$ make clean
$ make
gcc -c main.c
gcc -c calc.c
gcc main.o calc.o -o program
$ make
make: 'program' is up to date.
$ nano main.c
$ make
gcc -c main.c
gcc main.o calc.o -o program
$ nano calc.h
$ make
gcc -c main.c
gcc -c calc.c
gcc main.o calc.o -o program
$ make clean
rm -f program main.o calc.o
```

처음 `make`가 없어 설치한 뒤 실행했다. 변경이 없으면 다시 빌드하지 않았고, `main.c`를 수정하자 `main.o`와 실행 파일을 다시 만들었다. `calc.h`는 두 목적 파일의 의존성이므로 수정 후 둘 다 다시 컴파일되었다. Makefile의 레시피는 탭으로 들여쓴다.
