# 🧭 창의공학설계(AdventureDesign)

> 2026학년도 2학기에 수강하는 창의공학설계(AdventureDesign) 전공선택 과목의 C 언어 실습과 Chapter별 퀴즈 기록입니다.

C 자료형과 표준 입출력, 조건문·반복문·배열을 실습하고 Chapter별 퀴즈에 적용합니다.

<br>

## 📂 Overview

| Item | Description |
| :-- | :-- |
| **Type** | 전공선택 |
| **Period** | 2026학년도 2학기 |
| **Language** | C |
| **Recorded Weeks** | 4개 |
| **Source Files** | 38개 |
| **Quiz Files** | 21개 |

<br>

## 🧭 Course Progression

```text
C 자료형·변수와 데이터 표현
        ↓
printf·scanf와 산술 연산
        ↓
논리 연산과 if·switch·삼항 연산자
        ↓
반복문과 배열·주소 전달
        ↓
Chapter 03~07 퀴즈
```

<br>

## 📅 Learning Records

| Record | Topic | Main Practice | Files |
| :--: | :-- | :-- | --: |
| [Week 03](week-03) | C 자료형과 표준 입출력 | 정수·실수·문자 입력, ASCII 코드, 사칙연산 | 4 |
| [Week 04](week-04) | 연산자와 조건문 | 산술·논리 연산, if·switch·삼항 연산자, 홀짝 판별 | 6 |
| [Week 06](week-06) | 조건문과 반복문 | 점수 판정, 합계, `for`·`while`·`do while`, 구구단 | 4 |
| [Week 09](week-09) | 배열과 주소 전달 | 배열 채우기·행열 합, 값과 주소 전달 비교 | 3 |
| [Chapter 03 Quiz](chapter03-quiz) | 자료형·변수·상수 | 8·16진수, km-mile 변환, 원-달러 환산 | 3 |
| [Chapter 04 Quiz](chapter04-quiz) | 표준 입출력과 서식 | 문자 코드 출력, 면적 계산, `getchar`·`putchar` | 3 |
| [Chapter 05 Quiz](chapter05-quiz) | 수식과 함수 | 구의 부피·표면적, 복리, 판별식에 따른 이차방정식 실근 계산 | 3 |
| [Chapter 06 Quiz](chapter06-quiz) | 조건문 | 윤년, 월별 말일, 온도 변환 | 3 |
| [Chapter 07 Quiz](chapter07-quiz) | 반복문과 함수 | 소수, 복리, 숫자 패턴, 온도 변환, 이진수 처리 | 9 |

<br>

## 📖 Learning by Stage

### 1. C 자료형과 데이터 표현

3주차에는 정수형·실수형·문자형과 서식 지정자, ASCII 문자 코드를 실습했습니다. 진법 표현은 Chapter 03 퀴즈에 적용했습니다.

대표 실습:

- [자료형과 입출력](week-03/c-data-types-input-output.c)
- [정수·실수 입력](week-03/read_int_float.c)

### 2. 표준 입출력과 연산

3주차에는 `printf`, `scanf`를 사용한 콘솔 입출력과 산술 연산을 실습했습니다. `getchar`, `putchar`와 출력 서식은 Chapter 04 퀴즈에도 적용했습니다.

대표 실습:

- [두 정수의 덧셈](week-03/two_integer_addition.c)
- [Chapter 04 퀴즈](chapter04-quiz)

### 3. 연산자와 조건문

4주차에는 논리 연산, 형 변환, 전위·후위 증감 연산을 확인하고, `if`, `switch`, 삼항 연산자로 연산자 선택과 홀짝 판별을 구현했습니다. `switch`에서 `break`가 없을 때 다음 분기로 이어지는 동작도 확인했습니다.

대표 실습:

- [연산자 예제](week-04/operator-examples.c)
- [홀짝 판별](week-04/parity-conditions.c)
- [switch의 분기 흐름](week-04/switch-fallthrough.c)

### 4. 반복문과 배열

6주차에는 반복문으로 합계와 구구단을 출력하고 `break`, `continue`를 사용했습니다. 9주차에는 배열의 행·열 채우기와 합계, 함수에 값과 주소를 전달하는 예제를 작성했습니다.

대표 실습:

- [반복문과 구구단](week-06/multiplication-table-loops.c)
- [while과 do while 합계](week-06/while-loop-sums.c)
- [배열의 행·열 합계](week-09/array-row-column-sums.c)
- [값과 주소 전달](week-09/call-by-value-and-address.c)

### 5. Chapter 퀴즈

Chapter 03~07 퀴즈에는 단위·환율 변환, 출력 서식, 이차방정식 실근 계산, 윤년 판정, 소수 판별과 반복문·함수를 이용한 계산을 적용했습니다.

대표 실습:

- [Chapter 03 퀴즈](chapter03-quiz)
- [Chapter 04 퀴즈](chapter04-quiz)
- [Chapter 05 퀴즈](chapter05-quiz)
- [Chapter 06 퀴즈](chapter06-quiz)
- [Chapter 07 퀴즈](chapter07-quiz)

<br>

## 🗃️ Record Structure

| Path | Contents |
| :-- | :-- |
| [`week-03/`](week-03) | 자료형·입출력·사칙연산 실습 코드 4개 |
| [`week-04/`](week-04) | 연산자와 조건문 실습 코드 6개 |
| [`week-06/`](week-06) | 조건문과 반복문 실습 코드 4개 |
| [`week-09/`](week-09) | 배열과 주소 전달 실습 코드 3개 |
| [`chapter03-quiz/`](chapter03-quiz) | Chapter 03 퀴즈 코드 3개 |
| [`chapter04-quiz/`](chapter04-quiz) | Chapter 04 퀴즈 코드 3개 |
| [`chapter05-quiz/`](chapter05-quiz) | Chapter 05 퀴즈 코드 3개 |
| [`chapter06-quiz/`](chapter06-quiz) | Chapter 06 퀴즈 코드 3개 |
| [`chapter07-quiz/`](chapter07-quiz) | Chapter 07 퀴즈 코드 9개 |

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
- Chapter 05의 `pow`, `sqrt` 예제는 GCC에서 환경에 따라 `-lm` 옵션으로 수학 라이브러리를 연결해야 합니다.

<br>

## 🏷️ File Naming

| Pattern | Meaning |
| :-- | :-- |
| `week-NN/*.c` | 주차별 C 실습 코드 |
| `chapterNN-quiz/chapterNN-NN.c` | Chapter별 퀴즈 풀이 |

<br>

## 🔗 Navigation

- [1학년 2학기](../README.md)
- [저장소 대표 README](../../README.md)
