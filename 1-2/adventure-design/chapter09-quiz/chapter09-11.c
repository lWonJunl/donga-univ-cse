/*
    작성자: 최원준
    작성일: 2026-11-09
*/

#include <stdio.h>

void hexadecimal(int num) {
    if (num / 16 > 0) {
        hexadecimal(num / 16);
    }
    
    int remainder = num % 16;
    
    if (remainder < 10) {
        printf("%d", remainder);
    } else {
        printf("%c", 'A' + (remainder - 10));
    }
}

int main() {
    int num = 0;

    printf("10진수를 입력하면 16진수를 출력합니다.\n");
    printf("정수 입력 >> ");
    scanf(" %d", &num);
    
    printf("%d의 16진수는? ", num);
    hexadecimal(num);

    return 0;
}