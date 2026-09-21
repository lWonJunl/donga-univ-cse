#include <stdio.h>

int main() {
    int num1 = 0, num2 = 0, reno = 0;
    char op = ' ';

    printf("[사칙연산 프로그램]\n숫자1 입력 : ");
    scanf(" %d", &num1);
    printf("연산자 입력 : ");
    scanf(" %c", &op);
    printf("숫자2 입력 : ");
    scanf(" %d", &num2);

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

    printf("\n<결과>\n%d %c %d = %d", num1, op, num2, reno);
    return 0;
}