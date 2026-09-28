#include <stdio.h>

int main() {
    double x = 5, y = 10, result;
    char op = '-';

    switch(op) {
        case '+':
            printf("%.2f + %.2f = %.2f\n", x, y, x + y);
            break;
        case '-':
            printf("%.2f - %.2f = %.2f\n", x, y, x - y);
            break;
        default: 
            printf("연산자를 잘못 선택했습니다.\n");
    }
}