# 🐧 LinuxSystem

> 2026학년도 2학기에 수강하는 LinuxSystem 전공선택 과목의 명령어 학습 및 실습 기록입니다.

사용자 계정과 권한 관리부터 WSLg GUI 환경, Linux 파일·디렉터리 명령, `vi` 편집까지 주차별로 정리합니다.

<br>

## 📂 Overview

| Item | Description |
| :-- | :-- |
| **Type** | 전공선택 |
| **Period** | 2026학년도 2학기 |
| **Environment** | Ubuntu WSL 26.04 LTS, Windows PowerShell |
| **Recorded Classes** | 5차시 |
| **Command Entries** | 30개 |

<br>

## 🧭 Course Progression

```text
Linux 기초 활용
├── 사용자 권한과 전환: sudo, su
├── 사용자 계정 관리: adduser, useradd, passwd, userdel
├── WSL GUI 환경: WSL2, WSLg, x11-apps, xclock
└── 파일과 디렉터리
    ├── 시스템·경로 확인: uname, whoami, ls, pwd
    ├── 디렉터리와 파일 관리: cd, mkdir, rmdir, touch
    ├── 파일 내용 확인: cat, more, head, tail, wc
    └── 텍스트 편집: gedit, gnome-text-editor, vi
```

<br>

## 📅 Weekly Records

| Week | Topic | Main Practice |
| :--: | :-- | :-- |
| [01-02](week01-day02.md) | 사용자 권한과 전환 | `sudo`, `su` |
| [02-01](week02-day01.md) | 사용자 계정 관리 | `adduser`, `useradd`, `passwd`, `userdel` |
| [02-02](week02-day02.md) | WSL GUI 환경 구성 | WSL2·WSLg 확인, `x11-apps` 설치, `xclock` 실행 |
| [03-01](week03-day01.md) | Linux 기본 명령과 편집기 | 시스템 정보, 경로, 파일·디렉터리, `vi` 등 명령어 24개 |
| [03-02](week03-day02.md) | 파일·디렉터리 종합 실습 | `/etc/services` 확인, 파일 편집, Windows 드라이브 접근 |

<br>

## 📖 Learning by Stage

### 1. 사용자와 권한 관리

- `sudo`, `su`를 사용한 관리자 권한 실행과 사용자 전환
- `adduser`, `useradd`, `passwd`, `userdel`을 사용한 계정 생성·설정·삭제

### 2. WSL2·WSLg 환경 확인

- Windows PowerShell에서 WSL 버전과 실행 상태 확인
- Linux에서 `DISPLAY`, `WAYLAND_DISPLAY` 환경 변수 확인
- `x11-apps` 설치 후 `xclock` GUI 프로그램 실행

### 3. Linux 파일과 디렉터리 활용

- 시스템·사용자·현재 경로 정보 확인
- 디렉터리 생성과 이동, 파일 생성 및 내용 조회
- `cat`, `more`, `head`, `tail`, `wc`를 활용한 텍스트 확인
- `vi` 모드 전환, 이동, 수정, 삭제, 복사·붙여넣기, 검색·치환

### 4. 종합 실습

- `/etc/services` 내용을 여러 명령으로 조회하고 결과 비교
- 실습 디렉터리와 파일 생성 후 `vi`로 C 코드 작성
- `/mnt/c`를 통해 WSL에서 Windows C: 드라이브 접근

<br>

## ▶️ Running the Examples

명령어 예시는 Ubuntu WSL 터미널에서 실행합니다. WSL 상태와 버전 확인 명령은 Windows PowerShell에서 실행합니다.

```bash
pwd
ls -la
mkdir practice
touch practice/example.txt
cat practice/example.txt
vi practice/example.txt
```

```powershell
wsl -l -v
wsl --version
```

<br>

## ⚠️ Environment Notes

- 사용자 계정과 권한 설정에 따라 `sudo`, `su`의 실행 결과가 달라질 수 있습니다.
- WSLg GUI 프로그램은 Windows와 WSL 버전, 그래픽 환경 설정에 영향을 받을 수 있습니다.
- 계정 삭제나 파일 수정처럼 시스템 상태를 바꾸는 명령은 실행 대상을 확인한 뒤 사용합니다.

<br>

## 🏷️ File Naming

| Pattern | Meaning |
| :-- | :-- |
| `weekNN-dayNN.md` | 주차·차시별 명령어 및 실습 기록 |

<br>

## 🔗 Navigation

- [1학년 2학기](../README.md)
- [저장소 대표 README](../../README.md)
