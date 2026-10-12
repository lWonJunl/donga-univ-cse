#include <stdio.h>

int main() {
    int count = 0;

    printf("2부터 100까지의 소수\n");

    for (int i = 2; i <= 100; i++) {
        int is_prime = 1;

        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }

        if (is_prime) {
            printf("%2d\t", i);
            count++;

            if (count % 10 == 0) {
                printf("\n");
            }
        }
    }

    return 0;
}
