#include <stdio.h>

int unitConvert(int C) {
    float F = 0;
    F = (9.0 / 5.0) * C + 32;
    return (int)F;
}

int main() {
    for (int C=-60; C<1; C+=20) {
        printf("섭씨온도: %3d = 화씨온도: %3d\n", C, unitConvert(C));
    }

    return 0;
}