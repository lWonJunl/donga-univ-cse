# 12주차 1차시

## 배운 명령어

### 1. `dpkg --print-architecture`로 아키텍처 확인

| 항목 | 내용 |
| --- | --- |
| 명령어 | `dpkg --print-architecture` |
| 기능 | 시스템의 기본 패키지 아키텍처를 출력한다. |
| 옵션 | `--print-architecture`: 기본 아키텍처 출력 |
| 인자 | 없음 |

#### 사용 예시

```bash
dpkg --print-architecture
```

Ubuntu 패키지의 `amd64`는 x86-64, `arm64`는 64비트 ARM을 뜻한다. `all`은 CPU 아키텍처에 무관한 패키지를 나타낸다. 실행 가능 여부에는 운영체제와 라이브러리, ABI도 영향을 준다.

---

### 2. `apt update`와 `apt upgrade`

| 항목 | 내용 |
| --- | --- |
| 명령어 | `sudo apt update`<br>`sudo apt upgrade` |
| 기능 | 저장소의 로컬 패키지 목록을 갱신하거나 설치된 패키지를 업그레이드한다. |
| 옵션 | 자료의 예시에서는 사용하지 않음 |
| 인자 | `update`: 목록 갱신<br>`upgrade`: 설치된 패키지 업그레이드 |

#### 사용 예시

```bash
sudo apt update
sudo apt upgrade
```

`update`는 목록만 갱신하며 설치된 프로그램을 업그레이드하지 않는다. `install`이 매번 `update`를 자동 실행하지는 않으므로 목록이 오래되었거나 저장소를 추가한 경우 갱신한다. APT는 로컬 목록과 설치 상태를 바탕으로 의존성을 계산한다.

---

### 3. `apt search`, `show`, `list`로 패키지 조회

| 항목 | 내용 |
| --- | --- |
| 명령어 | `apt search 검색어`<br>`apt show 패키지`<br>`apt list --installed` |
| 기능 | 패키지를 검색하거나 상세 정보와 설치 목록을 확인한다. |
| 옵션 | `--installed`: 설치된 패키지만 나열 |
| 인자 | `검색어`: 이름이나 설명의 검색어<br>`패키지`: 상세 정보를 확인할 이름 |

#### 사용 예시

```bash
apt search tree
apt show tree
apt list --installed
```

`apt show`로 버전, 설명, 의존성 등을 확인할 수 있다. 조회 명령은 보통 `sudo`가 필요하지 않다.

---

### 4. `apt install`, `remove`, `purge`, `autoremove`

| 항목 | 내용 |
| --- | --- |
| 명령어 | `sudo apt install 패키지`<br>`sudo apt remove 패키지`<br>`sudo apt purge 패키지`<br>`sudo apt autoremove` |
| 기능 | 패키지를 설치하거나 제거하고 불필요한 자동 설치 의존성을 정리한다. |
| 옵션 | 자료의 예시에서는 사용하지 않음 |
| 인자 | `패키지`: 설치 또는 제거할 패키지 이름 |

#### 사용 예시

```bash
sudo apt install tree
tree --version
tree .
sudo apt remove tree
```

`remove`는 일부 설정 파일을 남길 수 있고, `purge`는 패키지가 관리하는 시스템 설정 파일도 제거한다. `autoremove`는 자동 설치된 패키지 중 더 이상 필요하지 않은 것을 제거하므로 제안 목록을 확인한다. APT는 필요한 패키지를 다운로드하고 실제 DEB 설치에 `dpkg`를 활용한다.

---

### 5. 저장소 설정 확인

| 항목 | 내용 |
| --- | --- |
| 명령어 | `ls 디렉터리`<br>`cat 파일` |
| 기능 | 저장소 설정 파일의 목록과 내용을 읽는다. |
| 옵션 | 자료의 예시에서는 사용하지 않음 |
| 인자 | `디렉터리`: 설정 파일 위치<br>`파일`: 확인할 설정 파일 |

#### 사용 예시

```bash
ls /etc/apt/sources.list.d/
cat /etc/apt/sources.list.d/ubuntu.sources
```

전통적인 설정 파일은 `/etc/apt/sources.list`, 최근 Ubuntu에서는 deb822 형식의 `ubuntu.sources`를 사용할 수 있다. 저장소는 패키지 파일과 버전·의존성 정보를 제공한다. Ubuntu의 구성 영역은 `main`, `restricted`, `universe`, `multiverse`로 구분된다. 신뢰할 수 있는 저장소와 서명 키를 사용한다.

---

### 6. `dpkg`로 설치된 패키지 조사

| 항목 | 내용 |
| --- | --- |
| 명령어 | `dpkg -l 패키지`<br>`dpkg -s 패키지`<br>`dpkg -L 패키지`<br>`dpkg -S 경로` |
| 기능 | 설치 상태와 패키지가 제공하는 파일을 조회한다. |
| 옵션 | `-l`: 상태 요약<br>`-s`: 상태와 정보<br>`-L`: 패키지 파일 목록<br>`-S`: 경로를 소유한 패키지 검색 |
| 인자 | `패키지`: 조사할 패키지<br>`경로`: 패키지 데이터베이스에서 찾을 파일 경로 |

#### 사용 예시

```bash
dpkg -l bash
dpkg -s bash
dpkg -L bash
dpkg -S /usr/bin/bash
```

`dpkg`는 DEB 패키지를 설치·제거·설정하고 로컬 상태를 조회한다. 저장소에서 의존성을 자동으로 다운로드하지는 않는다. 조회는 일반적으로 `sudo` 없이 가능하다.

---

### 7. `dpkg-deb`와 로컬 DEB 설치

| 항목 | 내용 |
| --- | --- |
| 명령어 | `dpkg-deb -I 파일.deb`<br>`dpkg-deb -c 파일.deb`<br>`sudo apt install ./파일.deb` |
| 기능 | DEB 파일을 설치 전에 조사하고 로컬 파일을 설치한다. |
| 옵션 | `-I`: 제어 정보<br>`-c`: 내부 파일 목록 |
| 인자 | `파일.deb`: 조사하거나 설치할 패키지 파일 |

#### 사용 예시

```bash
dpkg-deb -I example.deb
dpkg-deb -c example.deb
sudo apt install ./example.deb
```

DEB에는 패키지 이름·버전·의존성 등의 제어 정보와 설치할 데이터가 들어 있다. `sudo dpkg -i ./example.deb`도 설치 명령이지만 필요한 의존성을 저장소에서 자동으로 받지 않는다. 신뢰할 수 있는 파일만 설치한다.

---

### 8. `snap`으로 패키지 관리

| 항목 | 내용 |
| --- | --- |
| 명령어 | `snap list`<br>`snap find 검색어`<br>`sudo snap install 패키지`<br>`sudo snap refresh`<br>`sudo snap remove 패키지` |
| 기능 | Snap 패키지를 조회·검색·설치·갱신·제거한다. |
| 옵션 | 자료의 예시에서는 사용하지 않음 |
| 인자 | `검색어`: 검색할 이름<br>`패키지`: 설치하거나 제거할 이름 |

#### 사용 예시

```bash
snap list
snap find firefox
sudo snap install 패키지이름
sudo snap refresh
sudo snap remove 패키지이름
```

Snap은 `snapd`가 관리하며 공통 base snap과 권한에 따른 격리를 활용한다. WSL에서는 systemd와 snapd 구성에 따라 실행이 제한될 수 있다. Flatpak은 공통 런타임과 샌드박스를 활용하는 데스크톱 앱 배포 방식이며, AppImage는 단일 실행 파일 형태로 배포된다. AppImage도 일부 시스템 라이브러리에 의존할 수 있다.

---

### 9. `tar`로 아카이브 생성과 추출

| 항목 | 내용 |
| --- | --- |
| 명령어 | `tar -cvf 아카이브 대상`<br>`tar -tvf 아카이브`<br>`tar -xvf 아카이브` |
| 기능 | 파일과 디렉터리를 묶거나 목록을 확인하고 추출한다. |
| 옵션 | `-c`: 생성<br>`-t`: 목록<br>`-x`: 추출<br>`-v`: 처리 내용 출력<br>`-f`: 아카이브 파일 지정<br>`-C`: 추출 위치 변경 |
| 인자 | `아카이브`: tar 파일 이름<br>`대상`: 묶거나 선택하여 추출할 경로 |

#### 사용 예시

```bash
tar -cvf project.tar project/
tar -tvf project.tar
tar -xf project.tar project/main.c
mkdir -p output
tar -xvf project.tar -C output/
```

`-f` 다음에는 아카이브 파일 이름을 지정하며 `-C`의 대상 디렉터리는 미리 있어야 한다. tar는 디렉터리 구조와 파일 속성을 보존할 수 있지만 자체적으로 압축하지는 않는다.

---

### 10. `tar`와 압축 방식

| 항목 | 내용 |
| --- | --- |
| 명령어 | `tar -czf 파일.tar.gz 대상`<br>`tar -cjf 파일.tar.bz2 대상`<br>`tar -cJf 파일.tar.xz 대상` |
| 기능 | 아카이브를 생성하면서 지정한 방식으로 압축한다. |
| 옵션 | `-z`: gzip<br>`-j`: bzip2<br>`-J`: xz<br>`-c`: 생성<br>`-x`: 추출<br>`-t`: 목록 |
| 인자 | 압축 아카이브 이름과 처리할 경로 |

#### 사용 예시

```bash
tar -czvf project.tar.gz project/
tar -tzvf project.tar.gz
tar -xzvf project.tar.gz
tar -cjf project.tar.bz2 project/
tar -xjf project.tar.bz2
tar -cJf project.tar.xz project/
tar -xJf project.tar.xz
```

아카이브는 여러 파일을 묶고 압축은 데이터 크기를 줄이는 별도의 작업이다. `.tar.gz`는 tar 묶음에 gzip 압축을 적용한 형식이다. ZIP은 묶기와 압축을 함께 제공한다.

---

### 11. `gcc`로 컴파일과 링크

| 항목 | 내용 |
| --- | --- |
| 명령어 | `gcc 소스 -o 실행파일`<br>`gcc -c 소스`<br>`gcc 목적파일 -o 실행파일` |
| 기능 | C 소스를 컴파일하고 목적 파일과 라이브러리를 링크한다. |
| 옵션 | `-o`: 출력 파일 이름 지정<br>`-c`: 링크하지 않고 목적 파일 생성<br>`-E`: 전처리<br>`-S`: 어셈블리 코드 생성 |
| 인자 | `소스`: C 소스 파일<br>`목적파일`: 링크할 `.o` 파일 |

#### 사용 예시

```bash
gcc hello.c -o hello
./hello

gcc -c main.c
gcc -c calc.c
gcc main.o calc.o -o program
./program
```

GCC의 처리 과정은 전처리, 컴파일, 어셈블, 링크로 나눌 수 있다. 빌드는 이처럼 결과물을 만드는 전체 작업이다. 헤더에는 함수 선언을, 소스 파일에는 구현을 둘 수 있다. 변경되지 않은 목적 파일은 재사용할 수 있지만 공통 헤더가 바뀌면 이를 사용하는 소스도 다시 컴파일해야 할 수 있다.

---

### 12. `make`와 Makefile

| 항목 | 내용 |
| --- | --- |
| 명령어 | `make [타깃]` |
| 기능 | Makefile의 의존 관계와 수정 시각을 이용해 필요한 빌드 명령을 실행한다. |
| 옵션 | 자료의 예시에서는 사용하지 않음 |
| 인자 | `타깃`: 만들거나 실행할 대상. 생략하면 기본 타깃 사용 |

#### 사용 예시

```makefile
.PHONY: clean

program: main.o calc.o
	gcc main.o calc.o -o program

main.o: main.c calc.h
	gcc -c main.c

calc.o: calc.c calc.h
	gcc -c calc.c

clean:
	rm -f program main.o calc.o
```

```bash
make
make clean
```

레시피 앞에는 기본적으로 탭을 쓴다. `main.c`만 수정하면 `main.o`를 다시 만들고 프로그램을 링크하며, `calc.h`가 바뀌면 두 목적 파일이 모두 영향을 받는다. `.PHONY`는 같은 이름의 파일이 있어도 `clean`을 작업으로 취급한다.

---

### 13. 소스코드 빌드와 설치

| 항목 | 내용 |
| --- | --- |
| 명령어 | `./configure`<br>`make`<br>`sudo make install` |
| 기능 | 빌드 환경을 준비하고 빌드한 뒤 결과물을 설치한다. |
| 옵션 | 프로젝트의 설정에 따라 다름 |
| 인자 | `install`: 설치를 수행하는 Makefile 타깃 |

#### 사용 예시

```bash
tar -xzf project.tar.gz
cd project
./configure
make
sudo make install
```

이는 `configure`와 Makefile을 제공하는 전통적인 프로젝트의 예시다. 모든 프로젝트가 이 방식을 사용하지는 않으며 CMake나 Meson을 사용할 수도 있다. 설치 경로에 따라 `sudo`가 필요하지 않을 수 있고 `make install`이 빌드를 먼저 수행할 수도 있다.

소스코드는 사람이 작성한 프로그램이고 실행 파일은 실행할 수 있도록 구성된 파일이며 라이브러리는 다른 프로그램에 기능을 제공한다. 패키지는 설치 파일과 관련 정보를 묶은 배포 단위다. 의존하는 라이브러리의 서로 다른 버전이 공존할 수 없다면 충돌이 발생할 수 있다. `git clone`은 저장소를 복제하며, APT는 패키지를 관리하고 GCC와 Make는 각각 컴파일·링크와 빌드 자동화에 사용한다.
