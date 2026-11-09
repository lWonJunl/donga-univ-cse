/*
    작성자: 최원준
    작성일: 2026-11-08
*/

#include <stdio.h>
#define LOOP_NUM 10 

int sum(int i) {
    if (i <= 1) {
        return 1;
    }
    return i + sum(i - 1);
}

int main() {
    printf("1부터 %d까지 각각의 합을 구하는 프로그램 입니다.\n\n", LOOP_NUM);
    
    for (int i = 1; i < LOOP_NUM + 1; i++) {
        printf("1부터 %4d까지의 합: %6d\n", i, sum(i));
    }

    return 0;
}
