# 11주차 2차시

## 실습 기록

- 환경: `Ubuntu WSL 26.04 LTS`

### 실습 1. 산술 확장

```console
$ bash arithmetic.bash
2 × 1 = 2
2 × 2 = 4
$ nano arithmetic.bash
$ bash arithmetic.bash
3 × 1 = 3
3 × 2 = 6
```

`$((n * i))`는 산술식의 계산 결과로 확장되고, `((i++))`는 산술 연산으로 `i`를 증가시킨다.

---

### 실습 2. 반복문으로 구구단 출력

`gugudan.bash`에 2와 9를 입력해 각 단의 1부터 9까지 출력했다. 잘못된 입력에는 `오류: 2~9 사이의 정수를 입력하세요.`가 출력되었다. 실행 기록에는 `9\`를 입력해 오류가 난 뒤 9를 다시 입력한 과정도 있다. `while`의 조건을 만족하는 동안 곱셈 결과를 출력하고 반복 변수를 증가시킨다.

---

### 실습 3. 여러 경로 검사

```console
$ touch hello.bash
$ touch "test_file.txt"
$ bash check_many.bash hello.bash . nofile "test file.txt"
hello.bash : 일반 파일
. : 디렉터리
nofile : 기타 또는 없음
test file.txt : 기타 또는 없음
일반 파일 개수: 1
$ bash check_many.bash hello.bash . nofile "test_file.txt"
hello.bash : 일반 파일
. : 디렉터리
nofile : 기타 또는 없음
test_file.txt : 일반 파일
일반 파일 개수: 2
```

`for item in "$@"`는 각 명령줄 인수를 별도로 순회한다. 공백이 있는 이름도 따옴표로 전달하면 하나의 인수로 처리된다. 첫 번째 명령의 `test file.txt`는 실제로 만든 `test_file.txt`와 이름이 달라 없는 경로로 분류되었다.

---

### 실습 4. 메뉴 프로그램

`menu.bash`에서 파일 목록, 현재 위치, 사용자 이름을 확인하고 잘못된 선택을 처리했다. `while`은 종료 전까지 메뉴를 반복하고 `case`는 입력에 따라 실행할 명령을 선택한다. `menu5.bash`도 실행했다.

---

### 실습 5. 실행 추적과 오류 수정

```console
$ bash -v menu.bash
$ bash -x menu.bash
$ bash -vx menu.bash
$ bash -x menu_bug.bash
+ stop=1
+ true
$ bash menu_fixed.bash
```

`-v`는 읽은 스크립트 내용을, `-x`는 확장 후 실행되는 명령을 보여주며 `-vx`는 둘 다 표시한다. 오류가 있는 메뉴는 `stop=1`을 실행해도 `while true`의 조건이 바뀌지 않아 반복된다. 종료하려면 `break`로 반복문을 빠져나와야 한다. 위 추적은 관련 부분만 발췌했다.

---

### 실습 6. 구구단 함수

`print_table.bash`를 여러 입력으로 실행했으며 잘못된 입력에 오류 메시지가 출력되었다. 함수의 `$1`은 함수에 전달한 첫 번째 인수이고, `local`은 변수를 함수 범위로 제한한다. `return 1`은 함수의 실패 종료 상태를 나타낸다. 편집기에서 작성한 전체 코드와 종료 상태 출력은 실행 기록에서 확인할 수 없다.
