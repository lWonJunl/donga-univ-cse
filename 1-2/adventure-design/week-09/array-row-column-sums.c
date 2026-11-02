#include <stdio.h>

int main() {
    // 1번 : 
    int array_1[3][4] = {0};
    int num_1 = 2;

    for (int row = 0; row < 2; row++) {
        for (int colum = 0; colum < 3; colum++) {
            array_1[row][colum] = num_1;
            num_1 += 2;

            array_1[2][colum] += array_1[row][colum];
            array_1[row][3] += array_1[row][colum];
        }
    }
    for (int row = 0; row < 3; row++) {
        for (int colum = 0; colum < 4; colum++) {
            printf("%2d ", array_1[row][colum]);
        }
        printf("\n");
    }
    printf("\n");

    // 2번 : 
    int array_2[3][4] = {0};
    int num_2 = 3;
    
    for (int colum = 0; colum < 3; colum++) {
        for (int row = 0; row < 2; row++) {
            array_2[row][colum] = num_2;
            num_2 += 3;

            array_2[2][colum] += array_2[row][colum];
            array_2[row][3] += array_2[row][colum];
        }
    }
    for (int row = 0; row < 3; row++) {
        for (int colum = 0; colum < 4; colum++) {
            printf("%2d ", array_2[row][colum]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}