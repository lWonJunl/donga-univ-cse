#include <stdio.h>

void convertBinary(int num, int binaryNum[]) {
    int value = num;

    for (int i = 31; i >= 0; i--) {
        binaryNum[i] = value % 2;
        value /= 2;
    }
}

int main() {
    while (1) {
        int inputNum = 0;
        int binaryNum[32] = {0};

        printf("정수 또는 0(종료)을 입력 >> ");
        scanf(" %d", &inputNum);

        convertBinary(inputNum, binaryNum);

        printf("정수 %d의 32비트 값:\n", inputNum);

        for (int i = 0; i < 32; i++) {
            printf("%d", binaryNum[i]);
        }
        putchar('\n');

        if (inputNum == 0) {
            printf("종료합니다.\n");
            break;
        }
    }

    return 0;
}