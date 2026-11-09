/*
    작성자: 최원준
    작성일: 2026-11-08
*/

#include <stdio.h>

int main() {
    int tableArray[5][5] = {
        {78, 48, 78, 98, 0}, 
        {99, 92, 83, 29, 0}, 
        {29, 64, 83, 89, 0}, 
        {34, 78, 92, 56, 0}, 
        {0, 0, 0, 0, 0}
    };

    printf("다음 표의 세로와 가로, 그리고 모든 합을 구합니다.\n\n");
    printf("-------------------------------\n");
    for (int i=0; i<4; i++) {
        for (int k=0; k<4; k++) {
            printf("|%4d ", tableArray[i][k]);
        }
        printf("|\n");
    }
    printf("-------------------------------\n\n");

    printf("위 표의 세로와 가로합, 그리고 모든 합을\n각각 행과 열의 마지막에 구합니다\n\n");
    printf("-------------------------------\n");
    for (int i=0; i<5; i++) {
        for (int k=0; k<5; k++) {
            printf("|%4d ", tableArray[i][k]);
            if (k==4) {
                continue;
            }
            tableArray[i][4] += tableArray[i][k];

            if (i==4) {
                continue;
            }
            tableArray[4][k] += tableArray[i][k];
        }
        printf("|\n");
    }
    printf("-------------------------------\n");

    return 0;
}