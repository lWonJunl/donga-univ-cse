#include <stdio.h>

int main() {
    double num1 = 0, num2 = 0;

    printf("두 실수 입력: ");
    scanf(" %lf %lf", &num1, &num2);

    printf("가로: %lf 세로: %lf\n", num1, num2);
    printf("사각형 면적: %12.3lf\n", (num1 * num2));
    printf("삼각형 면적: %-12.3lf", (num1 * num2 * 0.5));
    return 0;
}