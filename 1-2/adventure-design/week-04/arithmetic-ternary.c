#include <stdio.h>

int main() {
    double x = 5, y = 10, result;
    char op = '-';

    (op == '+') ? printf("%.2f + %.2f = %.2f\n", x, y, x + y) : (op == '-') ? printf("%.2f - %.2f = %.2f\n", x, y, x - y) : printf("연산자를 잘못 선택했습니다.\n");
}