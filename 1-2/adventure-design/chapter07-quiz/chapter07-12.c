#include <math.h>
#include <stdio.h>

int main() {
    int principal = 1000000;
    const double interest_rate = 0.045;
    double total_amount = 0;

    for (int i = 1; i<=10; i++){
        total_amount = principal * pow(1 + interest_rate, i);
        printf("%2d년 총금액: %.2f\n", i, total_amount);
    }

    return 0;
}