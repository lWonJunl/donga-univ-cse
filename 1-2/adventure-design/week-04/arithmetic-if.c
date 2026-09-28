#include <stdio.h>

int main() {
    double x = 5, y = 10, result;
    char op = '-';

    if (op == '+') {
        printf("%.2f + %.2f = %.2f\n", x, y, x + y);
    } else if (op == '-') {
        printf("%.2f - %.2f = %.2f\n", x, y, x - y);
    } else {
        printf("연산자를 잘못 선택했습니다.\n");
    }
}