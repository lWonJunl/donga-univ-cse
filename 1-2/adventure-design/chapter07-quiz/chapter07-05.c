#include <stdio.h>

void printMultiplicationTable(int num) {
    for (int i = 1; i <= 9; i++) {
        printf("%d*%d=%d ", num, i, num * i);
    }
}

int main() {
    int num = 0;

    printf("출력할 구구단 2 ~ 9 사이의 정수 입력 >> ");
    scanf("%d", &num);

    printMultiplicationTable(num);

    return 0;
}