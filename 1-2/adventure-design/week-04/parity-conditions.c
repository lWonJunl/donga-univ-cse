#include <stdio.h>
#include <stdlib.h>

int main() {
    int num = 0;

    while (true) {
        printf("\n숫자 입력 >> ");
        scanf(" %d", &num);

        if (num == 0) {
            break;
        }

        if (abs(num) % 2 == 0) {
            printf("<if문> %d는 짝수입니다.\n", num);
        } else {
            printf("<if문> %d는 홀수입니다.\n", num);
        }

        switch (abs(num) % 2) {
            case 0 :
                printf("<switch문> %d는 짝수입니다.\n", num);
                break;
            default:
                printf("<switch문> %d는 홀수입니다.\n", num);
        }

        (abs(num) % 2 == 0) ? printf("<삼항연산자> %d는 짝수입니다.\n", num) : printf("<삼항연산자> %d는 홀수입니다.\n", num);
    }
}