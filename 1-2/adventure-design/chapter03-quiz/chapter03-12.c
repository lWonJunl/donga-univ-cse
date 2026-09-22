#include <stdio.h>
#define EXCHANGE_RATE 1120.0

int main() {
    int won = 1000000;
    double dollar = 0;
    dollar = won / EXCHANGE_RATE;

    printf("%d 원 => %lf 달러", won, dollar);
    return 0;
}