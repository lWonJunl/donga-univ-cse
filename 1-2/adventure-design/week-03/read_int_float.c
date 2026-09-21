/*
    개발자 : 최원준
    날  짜 : 26.9.21.
    주  제 : 정수와 실수를 입력받아 출력
*/
//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int a = 0;
    float b = 0;

    printf("정수 1개, 실수 1개 입력 (ex. 9 3.14) : ");
    scanf("%d %f", &a, &b);

    printf("정수 : %d\t 실수 : %f", a, b);
    return 0;
}
