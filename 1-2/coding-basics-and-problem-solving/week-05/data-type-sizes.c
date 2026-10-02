#include <stdio.h>

int main() {
    short sh = 12;
    int nt = 155;
    long long on = 1666;

    printf("[자료형의 크기를 알아보는 코드]\n");
    printf("1. short : %dbyte\n", sizeof(sh));
    printf("2. int : %dbyte\n", sizeof(nt));
    printf("3. long long : %ldbyte\n", sizeof(on));

    return 0;
}