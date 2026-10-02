# 🐧 LinuxSystem

> 2026학년도 2학기에 수강하는 LinuxSystem 전공선택 과목의 명령어 학습 및 실습 기록입니다.

사용자 계정과 권한 관리부터 WSLg GUI 환경, 파일·링크·접근권한, 쉘 입출력과 작업 제어까지 주차별로 정리합니다.

<br>

## 📂 Overview

| Item | Description |
| :-- | :-- |
| **Type** | 전공선택 |
| **Period** | 2026학년도 2학기 |
| **Environment** | Ubuntu WSL 26.04 LTS, Windows PowerShell |
| **Recorded Classes** | 9차시 |
| **Command Entries** | 57개 |

<br>

## 🧭 Course Progression

```text
사용자 권한과 계정 관리
        ↓
WSL2·WSLg GUI 환경
        ↓
파일·디렉터리 명령과 vi 편집
        ↓
파일·디렉터리 종합 실습
        ↓
복사·이동·삭제, 링크와 접근권한
        ↓
쉘 실행·작업 제어와 입출력 재지정
        ↓
파이프·명령어 조합과 대치
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
| [04-01](week04-day01.md) | 파일 관리와 접근권한 명령 | `cp`, `mv`, `rm`, `ln`, `file`, `chmod`, `chown`, `chgrp`, `touch` |
| [04-02](week04-day02.md) | 복사·링크·접근권한 실습 | 디렉터리 복사·삭제, 하드·심볼릭 링크 비교, 파일·디렉터리 권한 변경 |
| [05-01](week05-day01.md) | 쉘 명령과 입출력 | 작업 제어, 입출력 재지정, 파이프, 명령어 조합·대치 |
| [05-02](week05-day02.md) | 쉘 명령 종합 실습 | 작업 제어, 표준출력·오류 재지정, 파이프와 대치 결과 확인 |

<br>

## 📖 Learning by Stage

### 1. 사용자와 권한 관리

1~2주차에는 `sudo`, `su`로 권한 실행과 사용자 전환을 기록하고, `adduser`, `useradd`, `passwd`, `userdel`의 계정 관리 방법을 정리했습니다.

대표 기록:

- [관리자 권한과 사용자 전환](week01-day02.md)
- [사용자 계정 관리](week02-day01.md)

### 2. WSL2·WSLg 환경 확인

2주차 2차시에는 Windows PowerShell에서 WSL 버전과 실행 상태를 확인하고, Linux에서 `DISPLAY`, `WAYLAND_DISPLAY`를 확인한 뒤 `xclock`을 실행했습니다.

대표 기록:

- [WSL2·WSLg 환경 실습](week02-day02.md)

### 3. Linux 파일과 디렉터리 활용

3주차 1차시에는 시스템·사용자·경로 확인, 디렉터리 생성과 이동, 파일 내용 조회 명령을 정리했습니다. `vi`의 모드 전환, 이동, 수정, 검색·치환 방법도 기록했습니다.

대표 기록:

- [기본 명령어와 편집기](week03-day01.md)

### 4. 종합 실습

3주차 2차시에는 `/etc/services`를 여러 명령으로 조회하고, `vi`로 C 코드를 작성했습니다. `/mnt/c`를 통한 Windows 드라이브 접근도 실습했습니다.

대표 기록:

- [파일·디렉터리 종합 실습](week03-day02.md)

### 5. 파일 관리와 접근권한

4주차에는 `cp`, `mv`, `rm`과 `ln`의 사용법을 정리하고 복사·삭제와 하드·심볼릭 링크를 실습했습니다. `chmod`로 파일과 디렉터리의 접근권한을 바꿔 결과를 확인했고, `chown`, `chgrp`의 사용법도 기록했습니다.

대표 기록:

- [파일 관리와 접근권한 명령](week04-day01.md)
- [복사·링크·접근권한 실습](week04-day02.md)

### 6. 쉘과 명령어 조합

5주차에는 `chsh`, `jobs`, `fg`와 후면 실행을 학습하고, `>`, `>>`, `<`, `2>`를 통한 입출력 재지정과 `|` 파이프를 정리했습니다. 명령어의 성공 여부에 따른 실행, 파일 이름·명령어 대치와 따옴표 동작도 실습했습니다.

대표 기록:

- [쉘 명령과 입출력](week05-day01.md)
- [쉘 명령 종합 실습](week05-day02.md)

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
- `rm -r`은 디렉터리 아래 내용까지 삭제하므로 경로를 확인하고, 덮어쓰기·삭제 확인에는 `-i` 옵션을 사용합니다.

<br>

## 🏷️ File Naming

| Pattern | Meaning |
| :-- | :-- |
| `weekNN-dayNN.md` | 주차·차시별 명령어 및 실습 기록 |

<br>

## 🔗 Navigation

- [1학년 2학기](../README.md)
- [저장소 대표 README](../../README.md)
