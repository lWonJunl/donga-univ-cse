/*
    작성자: 최원준
    작성일: 2026-11-08
*/

#include <stdio.h>

int main() {
    int matrix_A[4][3] = {
        {46, 79, 78},
        {35, 57, 28},
        {43, 68, 76},
        {56, 78, 98}
    };
    
    int matrix_B[4][3] = {
        {78, 35, 99},
        {85, 82, 34},
        {58, 69, 29},
        {34, 59, 35}
    };

    printf("위의 두 행렬 합의 결과값입니다.\n\n");
    printf("----------------\n");
    for (int i=0; i<4; i++) {
        for (int k=0; k<3; k++) {
            printf("|%4d", matrix_A[i][k] + matrix_B[i][k]);
        }
        printf("|\n");
    }
    printf("----------------\n\n");

    printf("위의 두 행렬 차의 결과값입니다.\n");
    printf("----------------\n");
    for (int i=0; i<4; i++) {
        for (int k=0; k<3; k++) {
            printf("|%4d", matrix_A[i][k] - matrix_B[i][k]);
        }
        printf("|\n");
    }
    printf("----------------\n");

    return 0;
}