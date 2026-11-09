/*
    작성자: 최원준
    작성일: 2026-11-08
*/

#include <stdio.h>

int main() {
    int numArray[20] = {0}, count[10] = {0};
    int max_count = 0, max_num = 0;

    printf("0에서 9까지의 정수를 입력하세요\n");
    for (int i = 0; i < 20; i++) {
        scanf("%d", &numArray[i]);
    }

    for (int i=0; i<20; i++) {
        count[numArray[i]]++;
    }

    for (int k=0; k<10; k++) {
        if (count[k] > max_count) {
            max_count = count[k];
            max_num = k;
        }
    }

    printf("0~9 중 가장 많이 나온 숫자는 %d이고, %d번 나왔습니다.", max_num, max_count);
    return 0;
}