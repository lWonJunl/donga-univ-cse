#include <stdio.h>

int main() {
    char text = ' ';

    printf("문자입력: ");
    scanf(" %c", &text);

    printf("%c %#o %d %#x", text, (unsigned int)text, text, (unsigned int)text);
    return 0;
}