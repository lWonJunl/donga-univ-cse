#include <stdio.h>

int main() {
    char unit = ' ';
    float temp = 0, result = 0;

    printf("입력한 온도를 변환합니다.\n");
    printf("문자를 F나 f를 입력하면 썹씨로,\n");
    printf("문자를 C나 c를 입력하면 화씨로 변환합니다.\n");

    printf("문자 입력 >> ");
    scanf(" %c", &unit);
    printf("온도 입력 >> ");
    scanf(" %f", &temp);

    switch (unit) {
        case 'F': case 'f':
            result = (5.0 / 9.0) * (temp - 32);
            printf("화씨온도 %.2f는 썹씨온도로 %.2f입니다.", temp, result);
            break;

        case 'C': case 'c':
            result = (9.0 / 5.0) * temp + 32;
            printf("썹시온도 %.2f는 화씨온도로 %.2f입니다.", temp, result);
            break;

        default:
            printf("문자 입력 오류.");
            break;
    }

    return 0;
}
