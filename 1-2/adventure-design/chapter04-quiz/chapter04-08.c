#include <stdio.h>

int main() {
    char text = ' ';

    printf("문자 입력: ");
    text = getchar();

    putchar(text);
    printf("\n%d %#o %#x", text, (unsigned int)text, (unsigned int)text);
    return 0;
}