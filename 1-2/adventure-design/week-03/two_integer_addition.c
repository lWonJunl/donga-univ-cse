/*
    개발자 : 최원준
    날  짜 : 26.9.21.
    주  제 : 두 정수를 입력받아 연산 결과 출력
*/
//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int num1 = 0, num2 = 0, reno = 0;
    char op = ' ';

    printf("[사칙연산 프로그램]\n숫자1 입력 : ");
    if (scanf(" %d", &num1) != 1) {
        printf("숫자 입력 오류.");
        return 1;
    }

    printf("연산자 입력 : ");
    if (scanf(" %c", &op) != 1) {
        printf("연산자 입력 오류.");
        return 1;
    }

    printf("숫자2 입력 : ");
    if (scanf(" %d", &num2) != 1) {
        printf("숫자 입력 오류.");
        return 1;
    }

    if (op == '+') {
        reno = num1 + num2;
    } else if (op == '-') {
        reno = num1 - num2;
    } else if (op == '*') {
        reno = num1 * num2;
    } else if (op == '/') {
        reno = num1 / num2;
    } else if (op == '%') {
        reno = num1 % num2;
    } else {
        printf("연산자 입력 오류. 옳은 연산자를 입력해 주세요.");
        return 1;
    }

    if ((op == '/' || op == '%') && num2 == 0) {
        printf("0으로 나눌 수 없습니다.");
        return 1;
    }

    printf("\n<결과>\n%d %c %d = %d", num1, op, num2, reno);
    return 0;
}