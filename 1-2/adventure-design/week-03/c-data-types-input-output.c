#include <stdio.h>

int main(void) {
    float month = 0;
    month = 5.2;
    printf("1년은 몇 달? ");
    scanf("%f", &month);
    printf("1년은 %f달 \n\n", month);

    int day = 0;
    printf("1년은 몇 일? ");
    scanf("%d", &day);
    printf("1년은 %f달\t1달은 %d일 \n\n\n", month, day);

    char abc = ' ';
    printf("문자를 입력하시오. : ");
    scanf(" %c", &abc);
    printf("문자 %c는 ASCII 코드 숫자 %d입니다.", abc, abc);

    return 0;
}