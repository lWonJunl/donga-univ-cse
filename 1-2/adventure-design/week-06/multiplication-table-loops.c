#include <stdio.h>

int main() {
    int i = 0, k = 0;
    
    for (i = 2; i < 10; i++) {
        printf("=== %d단 시작 ===\n", i);

        for (k = 1; k < 10; k++) {
            printf("%d * %d = %2d\n", i, k, i*k);
        }

        printf("### %d단 끝 ###\n\n", i);
    }

    for (i = 2; i < 10; i++) {
        
        if (i % 2) {
            continue;
        } else if (i == 6) {
            break;
        }

        printf("=== %d단 시작 ===\n", i);

        for (k = 1; k < 10; k++) {
            printf("%d * %d = %2d\n", i, k, i*k);
        }

        printf("### %d단 끝 ###\n\n", i);

        
    }
}