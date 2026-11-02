#include <stdio.h>

int main() {
    // 1번 1x3배열 3의배수
    int array_1[3] = {0};

    for (int colum = 0; colum < 3; colum++) {
        array_1[colum] = (colum + 1) * 3;
    }

    for (int colum = 0; colum < 3; colum++) {
        printf("%d ", array_1[colum]);
    }
    printf("\n\n");

    // 2번 : 2x3배열 짝수 행 우선
    int array_2[2][3] = {0};
    int num_2 = 2;

    for (int row = 0; row < 2; row++) {
        for (int colum = 0; colum < 3; colum++) {
            array_2[row][colum] = num_2;
            num_2 += 2;
        }
    }

    for (int row = 0; row < 2; row++) {
        for (int colum = 0; colum < 3; colum++) {
            printf("%d ", array_2[row][colum]);
        }
        printf("\n");
    }
    printf("\n");

    // 3번 2x3배열 3의배수 열 우선
    int array_3[2][3] = {0};
    int num_3 = 3;

    for (int colum = 0; colum < 3; colum++) {
        for (int row = 0; row < 2; row++) {
            array_3[row][colum] = num_3;
            num_3 += 3;
        }
    }

    for (int row = 0; row < 3; row++) {
        for (int colum = 0; colum < 3; colum++) {
            printf("%d ", array_3[row][colum]);
        }
        printf("\n");
    }

    return 0;
}