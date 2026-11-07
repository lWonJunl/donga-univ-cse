#include <stdio.h>

void calculate(int *sum, int *i) {
    for (*i=1; (*sum+*i)<10001; (*i)++) {
        *sum += *i;
    }
}

int main() {
    int sum = 0, i = 0;

    printf("1부터 n까지의 합 중에서 10000을 넘지 않는 가장큰 합은?\n");
    calculate(&sum, &i);
    printf("1부터 %d까지의 합이 %d입니다.", i-1, sum);
    
    return 0;
}