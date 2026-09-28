#include <math.h>
#include <stdio.h>

int main(void)
{
    const double principal = 1000000.0;
    const double interest_rate = 0.045;
    int years;
    double total_amount;

    printf("예치 기간 입력(년) >> ");
    scanf("%d", &years);

    total_amount = principal * pow(1 + interest_rate, years);

    printf("이율 : 4.5%% 총금액: %.2f\n", total_amount);

    return 0;
}