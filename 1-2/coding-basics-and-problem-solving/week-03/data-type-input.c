#include <stdio.h>

int main(void) {
    int integerVal;
    char charVal;
    double doubleVal;

    printf("정수를 입력하세요 : ");
    scanf("%d", &integerVal);

    printf("문자를 입력하세요 : ");
    scanf(" %c", &charVal);

    printf("실수를 입력하세요 : ");
    scanf(" %lf", &doubleVal);

    printf("\n입력받은 정수 : %d\n", integerVal);
    printf("입력받은 문자 : %c\n", charVal);
    printf("입력받은 실수 : %lf\n", doubleVal);

    return 0;
}