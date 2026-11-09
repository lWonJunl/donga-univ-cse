/*
    작성자: 최원준
    작성일: 2026-11-09
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int duplicate(int num, int lotto[], int cnt) {
    for (int i = 0; i < cnt; i++) {
        if (lotto[i] == num) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int num = 0, lotto[6] = {0}, cnt = 0;
    srand((unsigned int)time(NULL));

    while(cnt < 6) {
        num = (rand() % 45) + 1;
        if (duplicate(num, lotto, cnt)) {
            continue;
        }
        lotto[cnt++] = num;
    }

    printf("로또 당첨 번호: ");
    for (int i = 0; i < 6; i++) {
        printf(" %d ", lotto[i]);
    }
}