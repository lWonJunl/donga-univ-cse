#include <stdio.h>
#include <math.h>

int main() {
    for (int row = 0; row <= 7; row++) {
        for (int column = 0; column <= 7 + row; column++) {
            if (column < 7 - row) {
                putchar(' ');
            } else {
                int number = abs(column - 7);
                printf("%d", number);
            }
        }
        putchar('\n');
    }

    return 0;
}
