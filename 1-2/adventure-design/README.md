# 🧭 창의공학설계(AdventureDesign)

> 2026학년도 2학기에 수강하는 창의공학설계(AdventureDesign) 전공선택 과목의 프로그래밍 이론 및 C 언어 실습 기록입니다.

프로그래밍 언어와 알고리즘의 기초부터 C 자료형, 변수, 표준 입출력, 연산까지 학습하고 Chapter별 퀴즈로 적용합니다.

<br>

## 📂 Overview

| Item | Description |
| :-- | :-- |
| **Type** | 전공선택 |
| **Period** | 2026학년도 2학기 |
| **Language** | C |
| **Recorded Weeks** | 2개 |
| **Lecture Notes** | 1개 |
| **Source Files** | 10개 |
| **Quiz Files** | 6개 |

<br>

## 🧭 Course Progression

```text
프로그래밍 기초와 C 언어
├── 프로그래밍 언어·번역 방식·알고리즘·순서도
├── C 프로그램 개발 과정과 오류 유형
├── 자료형·변수·진법·보수 표현
├── printf·scanf를 활용한 표준 입출력
├── 산술 연산과 조건문을 사용한 계산기
└── Chapter 03·04 퀴즈
    ├── 진법, 단위 변환, 상수와 환율 계산
    └── 문자 코드, 출력 서식, getchar·putchar
```

<br>

## 📅 Learning Records

| Record | Topic | Main Practice | Files |
| :--: | :-- | :-- | --: |
| [Week 02](week-02.md) | 프로그래밍 개요와 C 기초 이론 | 언어 수준, 컴파일러·인터프리터, 알고리즘, 개발 과정, 자료형 | 1 |
| [Week 03](week-03) | C 자료형과 표준 입출력 | 정수·실수·문자 입력, ASCII 코드, 사칙연산 | 4 |
| [Chapter 03 Quiz](chapter03-quiz) | 자료형·변수·상수 | 8·16진수, km-mile 변환, 원-달러 환산 | 3 |
| [Chapter 04 Quiz](chapter04-quiz) | 표준 입출력과 서식 | 문자 코드 출력, 면적 계산, `getchar`·`putchar` | 3 |

<br>

## 📖 Learning by Stage

### 1. 프로그래밍과 문제 해결 기초

- 저급·중급·고급 언어의 차이와 컴파일러·인터프리터 비교
- 문제 분해, 순차, 조건, 반복을 활용한 알고리즘 구성
- 순서도 기호와 C 프로그램의 편집·컴파일·링크·실행 과정

### 2. C 자료형과 데이터 표현

- 정수형·실수형·문자형과 자료형별 서식 지정자
- ASCII 문자 코드와 8진수·16진수 표현
- 부호와 절대치, 1의 보수, 2의 보수를 이용한 정수 표현

### 3. 표준 입출력과 연산

- `printf`, `scanf`, `getchar`, `putchar`를 사용한 콘솔 입출력
- 입력값을 변수에 저장하고 산술 연산 결과 출력
- 조건문으로 연산자를 구분하는 사칙연산 프로그램 작성

### 4. Chapter 퀴즈

- 함수와 상수를 사용한 km-mile 단위 변환 및 원-달러 환산
- 문자 값을 문자·8진수·10진수·16진수로 출력
- 출력 폭, 정렬, 정밀도를 적용한 사각형·삼각형 면적 출력

<br>

## 🗃️ Record Structure

| Path | Contents |
| :-- | :-- |
| [`week-02.md`](week-02.md) | Chapter 01~03 이론 정리 |
| [`week-03/`](week-03) | 자료형·입출력·사칙연산 실습 코드 4개 |
| [`chapter03-quiz/`](chapter03-quiz) | Chapter 03 퀴즈 코드 3개 |
| [`chapter04-quiz/`](chapter04-quiz) | Chapter 04 퀴즈 코드 3개 |

<br>

## ▶️ Running the Examples

GCC가 설치된 환경에서는 다음과 같이 각 소스 파일을 컴파일하고 실행할 수 있습니다.

```bash
gcc week-03/two_integer_addition.c -o calculator
./calculator
```

<br>

## ⚠️ Environment Notes

- 각 C 소스 파일은 독립적인 `main` 함수를 포함하므로 한 파일씩 컴파일합니다.
- `/`와 `%` 연산은 정수 피연산자를 사용하므로 정수 나눗셈과 나머지 계산으로 처리됩니다.
- 입력 함수의 서식 지정자는 변수의 자료형과 일치해야 합니다.

<br>

## 🏷️ File Naming

| Pattern | Meaning |
| :-- | :-- |
| `week-NN.md` | 주차별 이론 정리 |
| `week-NN/*.c` | 주차별 C 실습 코드 |
| `chapterNN-quiz/chapterNN-NN.c` | Chapter별 퀴즈 풀이 |

<br>

## 🔗 Navigation

- [1학년 2학기](../README.md)
- [저장소 대표 README](../../README.md)
