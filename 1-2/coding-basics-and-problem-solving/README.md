# 💻 코딩의기초와문제해결

> 2026학년도 2학기에 수강하는 코딩의기초와문제해결 기초과학및수학 과목의 C 언어 수업 기록입니다.

C 프로그램의 기본 구조와 표준 입출력, 자료형별 서식 지정, 변수와 산술 연산을 예제 코드로 학습합니다.

<br>

## 📂 Overview

| Item | Description |
| :-- | :-- |
| **Type** | 기초과학및수학 |
| **Period** | 2026학년도 2학기 |
| **Language** | C |
| **Recorded Weeks** | 1개 |
| **Source Files** | 6개 |

<br>

## 🧭 Course Progression

```text
C 프로그래밍 기초
├── 프로그램 구조: #include, main, return
├── 표준 출력: printf
├── 자료형과 서식 지정자: 정수, 실수, 문자, 문자열
├── 출력 폭·정렬·정밀도 지정
├── 표준 입력: scanf
└── 변수와 산술 연산
```

<br>

## 📅 Weekly Records

| Week | Topic | Main Practice | Files |
| :--: | :-- | :-- | --: |
| [03](week-03) | C 표준 입출력과 자료형 | `printf`, `scanf`, 서식 지정, 덧셈 | 6 |

<br>

## 📖 Learning by Stage

### 1. C 프로그램의 기본 구조

[`helloworld.c`](week-03/helloworld.c)에서 `stdio.h`, `main` 함수, `printf`, `return`으로 구성된 기본 프로그램을 작성했습니다.

### 2. 자료형과 출력 형식

정수·실수·문자·문자열을 각각 `%d`, `%f`, `%c`, `%s`로 출력하고, 필드 폭과 왼쪽 정렬, 소수점 정밀도, 문자열 길이 제한을 적용했습니다.

### 3. 표준 입력과 변수

`scanf`로 정수, 문자, 실수를 입력받아 변수에 저장한 뒤 자료형에 맞는 서식 지정자로 출력했습니다.

### 4. 산술 연산

두 정수의 덧셈과 입력된 두 피연산자의 합을 계산하고 결과를 수식 형태로 출력했습니다.

<br>

## 🗃️ Source Files

| File | Practice |
| :-- | :-- |
| [`helloworld.c`](week-03/helloworld.c) | 첫 C 프로그램과 문자열 출력 |
| [`ex02_01.c`](week-03/ex02_01.c) | 정수 변수와 덧셈 |
| [`ex02_02.c`](week-03/ex02_02.c) | 자료형별 서식 지정자 |
| [`ex.02_07.c`](week-03/ex.02_07.c) | 두 정수와 연산자 입력, 덧셈 결과 출력 |
| [`lap_2-1.c`](week-03/lap_2-1.c) | 출력 폭·정렬·정밀도 지정 |
| [`lap_2-2.c`](week-03/lap_2-2.c) | 정수·문자·실수 표준 입력 |

<br>

## ▶️ Running the Examples

GCC가 설치된 환경에서는 다음과 같이 각 소스 파일을 컴파일하고 실행할 수 있습니다.

```bash
gcc week-03/helloworld.c -o helloworld
./helloworld
```

<br>

## ⚠️ Environment Notes

- `scanf`의 서식 지정자는 저장할 변수의 자료형과 일치해야 합니다.
- 문자 입력 앞의 공백(`" %c"`)은 입력 버퍼에 남은 공백이나 줄바꿈을 건너뛰는 데 사용합니다.
- 소스 파일별로 `main` 함수가 있으므로 한 파일씩 컴파일합니다.

<br>

## 🏷️ File Naming

| Pattern | Meaning |
| :-- | :-- |
| `week-NN/` | 주차별 실습 디렉터리 |
| `exNN_NN.c`, `ex.NN_NN.c` | 교재 예제 |
| `lap_N-N.c` | 수업 실습 문제 |

<br>

## 🔗 Navigation

- [1학년 2학기](../README.md)
- [저장소 대표 README](../../README.md)
