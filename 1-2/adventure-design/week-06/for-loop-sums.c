#include <stdio.h>
#define START 1
#define LAST 10

int main() {
    int i = 0;
    int sum = 0, sum1 = 0, sum2 = 0;

    // i <= 10
    for (i = 1; i <= 10; i++) {
        sum += i;
    }
    printf("%d ~ %d의 합 = %d\n", 1, 10, sum);

    // i < 11
    for (i = 1, sum = 0; i < 11; i++) {
        sum += i;
    }
    printf("%d ~ %d의 합 = %d\n", 1, 10, sum);

    // 매크로 상수
    for (i = START, sum = 0; i < LAST + 1; i++) {
        sum += i;
    }
    printf("%d ~ %d의 합 = %d\n", 1, 10, sum);
    
    // 1 3 5 7 9 합 (for)
    for (i = 1, sum = 0; i < 11; i += 2) {
        sum += i;
        printf("%d ", i);
    }
    printf("합 = %d\n", sum);

    // 2 4 6 8 10 합 (for)
    for (i = 2, sum = 0; i < 11; i += 2) {
        sum += i;
        printf("%d ", i);
    }
    printf("합 = %d\n", sum);

    // 1 + 2 + ... + 10 = 55(for)
    for (i = 1, sum = 0; i < 11; i++) {
        sum += i;
        printf("%d", i);

        if (i != 10) {
            printf(" + ");
        } else {
            printf(" = %d\n", sum);
        }
    }

    return 0;
}