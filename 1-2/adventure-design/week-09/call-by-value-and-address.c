#include <stdio.h>

int callByValue(int a, int b) {
    printf("callByValue 함수 호출 전(함수내부) a = %d, b = %d \n", a, b);
    a = 9, b = 7;
    printf("callByValue 함수 호출 후(함수내부) a = %d, b = %d \n", a, b);
}

int callByAddress(int *a, int *b) {
    printf("callByValue 함수 호출 전(함수내부) a = %d, b = %d \n", *a, *b);
    *a = 9, *b = 7;
    printf("callByValue 함수 호출 후(함수내부) a = %d, b = %d \n", *a, *b);
}

int main() {
    int num, sum, a = 5, b = 10;

    printf("callByValue 함수 호출 전(main) a = %d, b = %d \n", a, b);
    callByValue(a, b);
    printf("callByValue 함수 호출 후(main) a = %d, b = %d \n", a, b);
    printf("\n");
    printf("callByAddress 함수 호출 전(main) a = %d, b = %d \n", a, b);
    callByAddress(&a, &b);
    printf("callByAddress 함수 호출 후(main) a = %d, b = %d \n", a, b);

}

