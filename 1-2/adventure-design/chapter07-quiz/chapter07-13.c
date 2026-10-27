#include <stdio.h>

int main() {
    for (int i=1; i<6; i++) {
        for (int k=5; k>0; k--) {
            if (i - k < 0) {
                putchar(' ');
            } else {
                printf("%d", k); 
            }
        }
        putchar('\n');
    }
}