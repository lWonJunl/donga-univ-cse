#include <stdio.h>

int main() {
    int i = 1, sum1 = 0;
    while(i < 11) {
        sum1 += i++;
    }
    printf("1 ~ 10의 합 (while) : %d\n", sum1);

    int k = 1, sum2 = 0;
    do {
        sum2 += k++;
    } while (k < 11);
    printf("1 ~ 10의 합 (do while) : %d", sum2);
}