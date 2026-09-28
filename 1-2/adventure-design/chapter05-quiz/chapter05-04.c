
#include <stdio.h>

int main(void)
{
    const double pi = 3.14;
    const double radius = 8.32;
    double v, s;

    v = (4.0 / 3.0) * pi * radius * radius * radius;
    s = 4 * pi * radius * radius;

    printf("구의 체적은 %.3f 입니다\n", v);
    printf("구의 표면적은 %.3f 입니다\n", s);

    return 0;
}
