#include <math.h>
#include <stdio.h>

int main(void)
{
    double a, b, c;
    double discriminant;
    double root1, root2;
    double check1, check2;

    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0) {
        printf("2차방정식의 계수 a는 0이 될 수 없습니다.\n");
        return 1;
    }

    discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        printf("실근이 없습니다.\n");
        return 0;
    }

    root1 = (-b + sqrt(discriminant)) / (2 * a);
    root2 = (-b - sqrt(discriminant)) / (2 * a);

    check1 = a * root1 * root1 + b * root1 + c;
    check2 = a * root2 * root2 + b * root2 + c;

    printf("해1 : %.3f\n", root1);
    printf("검증 계산 : %.3f\n", check1);
    printf("해2 : %.3f\n", root2);
    printf("검증계산 : %.3f\n", check2);

    return 0;
}
