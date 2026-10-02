# 💻 코딩의기초와문제해결

> 2026학년도 2학기에 수강하는 코딩의기초와문제해결 기초과학및수학 과목의 C 언어 수업 기록입니다.

C 프로그램의 기본 구조와 표준 입출력, 자료형·상수, 형 변환과 정수 범위를 예제 코드로 학습합니다.

<br>

## 📂 Overview

| Item | Description |
| :-- | :-- |
| **Type** | 기초과학및수학 |
| **Period** | 2026학년도 2학기 |
| **Language** | C |
| **Recorded Weeks** | 2개 |
| **Source Files** | 13개 |

<br>

## 🧭 Course Progression

```text
C 프로그램 구조와 printf
        ↓
자료형·서식 지정자와 출력 형식
        ↓
scanf를 이용한 표준 입력
        ↓
변수와 덧셈 연산
        ↓
자료형 크기·상수와 형 변환
        ↓
정수 오버플로·언더플로
```

<br>

## 📅 Weekly Records

| Week | Topic | Main Practice | Files |
| :--: | :-- | :-- | --: |
| [03](week-03) | C 표준 입출력과 자료형 | `printf`, `scanf`, 서식 지정, 덧셈 | 6 |
| [05](week-05) | 자료형·상수와 정수 범위 | `sizeof`, `const`, `#define`, 형 변환, 오버플로·언더플로 | 7 |

<br>

## 📖 Learning by Stage

### 1. C 프로그램의 기본 구조

[`hello-world.c`](week-03/hello-world.c)에서 `stdio.h`, `main` 함수, `printf`, `return`으로 구성된 기본 프로그램을 작성했습니다.

대표 실습:

- [첫 C 프로그램](week-03/hello-world.c)

### 2. 자료형과 출력 형식

정수·실수·문자·문자열을 각각 `%d`, `%f`, `%c`, `%s`로 출력하고, 필드 폭과 왼쪽 정렬, 소수점 정밀도, 문자열 길이 제한을 적용했습니다.

대표 실습:

- [자료형별 서식 지정자](week-03/format-specifiers.c)
- [출력 폭·정렬·정밀도](week-03/output-formatting.c)

### 3. 표준 입력과 변수

`scanf`로 정수, 문자, 실수를 입력받아 변수에 저장한 뒤 자료형에 맞는 서식 지정자로 출력했습니다.

대표 실습:

- [정수·문자·실수 입력](week-03/data-type-input.c)

### 4. 산술 연산

두 정수의 덧셈과 입력된 두 피연산자의 합을 계산하고 결과를 수식 형태로 출력했습니다.

대표 실습:

- [정수 변수와 덧셈](week-03/integer-addition.c)
- [두 피연산자의 합](week-03/addition-expression-input.c)

### 5. 자료형·상수와 형 변환

5주차에는 `sizeof`로 자료형별 크기를 출력하고, `const`와 `#define`으로 상수를 정의했습니다. `double` 값을 `int`에 대입할 때 암시적 변환과 명시적 형 변환을 비교했습니다.

대표 실습:

- [자료형 크기](week-05/data-type-sizes.c)
- [실수 상수](week-05/const-float.c)
- [기호 상수](week-05/symbolic-constant.c)
- [명시적 형 변환](week-05/explicit-type-conversion.c)
- [암시적 형 변환](week-05/implicit-type-conversion.c)

### 6. 정수 범위

부호 있는 정수와 부호 없는 정수의 경계값에서 계산 결과를 출력하는 예제를 작성했습니다.

대표 실습:

- [정수 오버플로](week-05/integer-overflow.c)
- [정수 언더플로](week-05/integer-underflow.c)

<br>

## 🗃️ Source Files

| File | Practice |
| :-- | :-- |
| [`hello-world.c`](week-03/hello-world.c) | 첫 C 프로그램과 문자열 출력 |
| [`integer-addition.c`](week-03/integer-addition.c) | 정수 변수와 덧셈 |
| [`format-specifiers.c`](week-03/format-specifiers.c) | 자료형별 서식 지정자 |
| [`addition-expression-input.c`](week-03/addition-expression-input.c) | 두 정수와 연산자 입력, 덧셈 결과 출력 |
| [`output-formatting.c`](week-03/output-formatting.c) | 출력 폭·정렬·정밀도 지정 |
| [`data-type-input.c`](week-03/data-type-input.c) | 정수·문자·실수 표준 입력 |
| [`data-type-sizes.c`](week-05/data-type-sizes.c) | 자료형별 크기 확인 |
| [`const-float.c`](week-05/const-float.c) | `const` 실수와 출력 서식 |
| [`symbolic-constant.c`](week-05/symbolic-constant.c) | `#define`으로 원의 넓이 계산 |
| [`explicit-type-conversion.c`](week-05/explicit-type-conversion.c) | 명시적 형 변환 |
| [`implicit-type-conversion.c`](week-05/implicit-type-conversion.c) | 암시적 형 변환 |
| [`integer-overflow.c`](week-05/integer-overflow.c) | 정수 경계값의 덧셈 |
| [`integer-underflow.c`](week-05/integer-underflow.c) | 정수 경계값의 뺄셈 |

<br>

## ▶️ Running the Examples

GCC가 설치된 환경에서는 다음과 같이 각 소스 파일을 컴파일하고 실행할 수 있습니다.

```bash
gcc week-03/hello-world.c -o hello-world
./hello-world
```

<br>

## ⚠️ Environment Notes

- `scanf`의 서식 지정자는 저장할 변수의 자료형과 일치해야 합니다.
- 문자 입력 앞의 공백(`" %c"`)은 입력 버퍼에 남은 공백이나 줄바꿈을 건너뛰는 데 사용합니다.
- 소스 파일별로 `main` 함수가 있으므로 한 파일씩 컴파일합니다.
- 부호 있는 정수의 오버플로·언더플로 결과는 C에서 정의되지 않으므로 실행 환경에 따라 달라질 수 있습니다.

<br>

## 🏷️ File Naming

| Pattern | Meaning |
| :-- | :-- |
| `week-NN/` | 주차별 실습 디렉터리 |
| `topic-description.c` | 코드의 핵심 내용이나 기능 |

<br>

## 🔗 Navigation

- [1학년 2학기](../README.md)
- [저장소 대표 README](../../README.md)
