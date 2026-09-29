#include <stdio.h>
#define EXCHANGE_RATE 1120.0

int main() {
    int won = 1000000;
    printf("%d 원 => %lf 달러", won, won / EXCHANGE_RATE);
    return 0;
}