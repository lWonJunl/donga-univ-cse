#include <math.h>
#include <stdio.h>

int main(void)
{
    int a = 2, b = 3, c = -4;
    double discriminant = 0;
    double solution1 = 0, solution2 = 0;
    double check1 = 0, check2 = 0;

    discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        printf("실근이 없습니다.\n");
        return 0;
    }

    solution1 = (-b + sqrt(discriminant)) / (2 * a);
    solution2 = (-b - sqrt(discriminant)) / (2 * a);

    check1 = a * solution1 * solution1 + b * solution1 + c;
    check2 = a * solution2 * solution2 + b * solution2 + c;

    printf("해1 : %.3f\n", solution1);
    printf("검증 계산 : %.3f\n", check1);
    printf("해2 : %.3f\n", solution2);
    printf("검증계산 : %.3f\n", check2);

    return 0;
}