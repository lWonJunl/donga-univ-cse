#include <stdio.h>

int main() {
    int a = 0;
    float b = 0;

    printf("정수 1개, 실수 1개 입력 (ex. 9 3.14) : ");
    scanf("%d %f", &a, &b);

    printf("정수 : %d\t 실수 : %f", a, b);
    return 0;
}
