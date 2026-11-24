#include <stdio.h>

#define SIZE 5

struct strc
{
    int value;
    int rank;
};

int main() {
    struct strc rank[SIZE] = {{4, 1}, {3, 1}, {7, 1}, {1, 1}, {5, 1}};

    for (int i=0; i<SIZE; i++) {
        for (int k=0; k<SIZE; k++){
            if (rank[k].value > rank[i].value) {
                rank[i].rank += 1;
            }
        }
    } 

    for (int j = 0; j < SIZE; j++) {
        printf("값: %d, 순위: %d\n", rank[j].value, rank[j].rank);
    }
    putchar('\n');
    return 0;
}
