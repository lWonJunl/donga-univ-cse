# 9주차 2차시

> 수업 날짜: `2026-10-28`

## 실습 기록

- 환경: `Ubuntu WSL 26.04 LTS`

### 실습 1. Bash 스크립트 실행과 권한 확인

#### 실행한 명령어와 결과

```console
$ cd week09
$ cat > hello.bash
#!/bin/bash
echo "안녕하세요. Bash 실습입니다."
$ bash hello.bash
안녕하세요. �Bash 실습입니다.
$ chmod +x hello.bash
$ ./hello.bash
안녕하세요. �Bash 실습입니다.
$ chmod -x hello.bash
$ ./hello.bash
bash: ./hello.bash: Permission denied
$ bash hello.bash
안녕하세요. �Bash 실습입니다.
```

`chmod +x`로 실행 권한을 추가하자 `./hello.bash`가 실행되었고, 권한을 제거하자 직접 실행이 거부되었다. 직접 실행에는 실행 권한이 필요하지만, `bash hello.bash`는 Bash가 스크립트를 읽어 실행하므로 파일의 읽기 권한이 필요하다.

실행 기록에 표시된 `�` 문자는 그대로 옮겼다. 작성한 코드에는 이 문자가 없다.

---

### 실습 2. 이름과 과목을 입력받아 출력

#### 실행한 명령어와 결과

```console
$ cat > greet.bash
#!/bin/bash

echo -n "이름 입력: "
read -r name

if [ -z "$name" ]; then
    echo "이름을 입력하지 않았습니다."
    exit 1
fi

echo "환영합니다, $name 님!"

echo -n "좋아하는 과목 입력: "
read -r subject

echo "$name 님이 좋아하는 과목은 $subject 입니다."
$ bash greet.bash
이름 입력: OOO
환영합니다, OOO 님!
좋아하는 과목 입력: XXX
OOO 님이 좋아하는 과목은 XXX 입니다.
$ bash greet.bash
이름 입력: O O
환영합니다, O O 님!
좋아하는 과목 입력: X X
O O 님이 좋아하는 과목은 X X 입니다.
$ bash greet.bash
이름 입력:
이름을 입력하지 않았습니다.
```

`read -r`로 입력을 변수에 저장하고 `echo -n`으로 줄을 바꾸지 않고 입력 안내를 출력했다. 공백이 포함된 이름과 과목도 입력한 그대로 출력되었다. `[ -z "$name" ]`은 이름이 빈 문자열인지 검사하며, 빈 경우 안내문을 출력하고 `exit 1`로 종료한다.

---

### 실습 3. 명령줄 인수로 인사와 학과 출력

#### 실행한 명령어와 결과

```console
$ cat > greet_arg.bash
#!/bin/bash

if [ "$#" -eq 0 ]; then
    echo "사용법: bash greet_arg.bash 이름 [학과]"
    exit 1
fi

echo "$1 님, 반갑습니다."

if [ "$#" -ge 2 ]; then
    echo "학과: $2"
fi
$ ./greet_arg.bash
bash: ./greet_arg.bash: Permission denied
$ bash greet_arg.bash
사용법: bash greet_arg.bash 이름 [학과]
$ 홍길동
홍길동: command not found
$ bash greet_arg.bash 홍길동
홍길동 님, 반갑습니다.
$ bash greet_arg.bash 홍길동 컴퓨터공학과
홍길동 님, 반갑습니다.
학과: 컴퓨터공학과
$ bash greet_arg.bash 홍길동 컴퓨터공학과
홍길동 님, 반갑습니다.
학과: 컴퓨터공학과
$ bash greet_arg.bash
사용법: bash greet_arg.bash 이름 [학과]
```

`$#`은 인수의 개수이고 `$1`과 `$2`는 각각 첫 번째와 두 번째 인수이다. 인수가 없으면 사용법을 출력하고 종료하며, 두 개 이상이면 학과도 출력한다. 직접 실행은 권한 오류가 났고, `홍길동`을 단독으로 입력했을 때는 셸이 이를 명령어로 해석해 찾을 수 없다고 출력했다.

---

### 실습 4. 파일과 디렉터리 구별

#### 실행한 명령어와 결과

```console
$ cat > check_path.bash
#!/bin/bash

if [ "$#" -eq 0 ]; then
    echo "사용법: bash check_path.bash 경로"
    exit 1
fi

if [ -f "$1" ]; then
    echo "일반 파일입니다."
elif [ -d "$1" ]; then
    echo "디렉터리입니다."
else
    echo "일반 파일이나 디렉터리가 아닙니다."
fi
$ bash check_path.bash hello.bash
일반 파일입니다.
$ bash check_path.bash .
디렉터리입니다.
$ bash check_path.bash 없는파일
일반 파일이나 디렉터리가 아닙니다.
$ bash check_path.bash
사용법: bash check_path.bash 경로
$ touch "공백 있는 파일.txt"
$ bash check_path.bash "공백 있는 파일.txt"
일반 파일입니다.
```

`-f`는 경로가 일반 파일인지, `-d`는 디렉터리인지 검사한다. 두 조건에 해당하지 않는 경로는 `else`에서 처리하고, 인수가 없으면 사용법을 출력한 뒤 종료한다. 공백이 있는 파일 이름은 따옴표로 묶어 하나의 인수로 전달했으며, 스크립트에서도 `"$1"`로 묶어 검사했다.

---

### 실습 5. 실행 흐름 정리

- `$#`은 스크립트에 전달된 명령줄 인수의 개수이다.
- `$1`은 첫 번째 명령줄 인수이며, 실습 3에서는 이름, 실습 4에서는 검사할 경로로 사용했다.
- `exit 1`은 종료 상태 `1`을 반환하고 스크립트 실행을 끝낸다.
- `-f`는 일반 파일을, `-d`는 디렉터리를 검사한다.
- 가장 어려웠던 부분과 해결 방법은 제공된 실행 기록에서 확인할 수 없다.
