/*
    작성자 : 최원준
    작성일 : 2026-11-06
*/

#include <stdio.h>

int isValid(int num) {
    if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0 || num % 7 == 0) {
        return 0;
    }

    return 1;
}

int main() {
    int count = 0;

    for (int i = 1; i <= 100; i++) {
        if (isValid(i) == 0) {
            continue;
        }

        printf("%2d\t", i);
        count++;

        if (count % 10 == 0) {
            putchar('\n');
        }
    }

    return 0;
}