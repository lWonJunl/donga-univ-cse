# 2주차 2차시

> 수업 날짜: `2026-09-09`

---

## 실습 기록

- 환경: `Ubuntu WSL 26.04 LTS` 및 `Windows PowerShell`

### 실습 1. 패키지 목록 갱신

#### 실행한 명령어

```console
$ sudo apt update
```

패키지 목록을 최신 상태로 갱신했다.

---

### 실습 2. X11 앱 설치

#### 실행한 명령어

```console
$ sudo apt install x11-apps
```

`x11-apps`를 설치했다. 이 패키지는 `xclock`처럼 X11 기반 GUI 프로그램을 실행할 때 사용한다.

### 실습 3. WSL2 확인

#### 실행한 명령어

```bash
wsl -l -v
```

#### 실행 결과

```text
  NAME            STATE           VERSION
* Ubuntu-26.04    Running         2
```

### 실습 4. WSLg 버전 확인

#### 실행한 명령어

```bash
wsl --version
```

#### 실행 결과
```text
WSL 버전: 2.7.10.0
커널 버전: 6.18.33.2-2
WSLg 버전: 1.0.73.2
MSRDC 버전: 1.2.6676
Direct3D 버전: 1.611.1-81528511
DXCore 버전: 10.0.26100.1-240331-1435.ge-release
Windows 버전: 10.0.26200.9168
```

### 실습 5. 환경 변수 확인

#### 실행한 명령어와 결과

```console
$ echo $WAYLAND_DISPLAY
wayland-0

$ echo $DISPLAY
:0
```

### 실습 6. GUI 프로그램 실행

#### 실행한 명령어와 결과

```console
$ xclock
Warning: Missing charsets in String to FontSet conversion
```

시계 창이 화면에 표시되어 WSLg를 통해 Linux GUI 프로그램이 정상적으로 실행되는 것을 확인했다.
