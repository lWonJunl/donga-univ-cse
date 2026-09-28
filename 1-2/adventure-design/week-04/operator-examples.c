#include <stdio.h>

int main() {
    int a = 10, b = 4, c = 0;
    float x = 10, y = 2, z = 0;

    c = a > b && x > y;     // True는 1, False는 0으로 저장
    printf("c = %d\n", c);

    c = a < b && x > y;
    printf("c = %d\n", c);

    c = (float)a / b;
    printf("a = %d b = %d c = %d\n", a, b, c);

    z = (float)a / b;
    printf("a = %d b = %d z = %f\n", a, b, z);

    z = a / b;
    printf("1) a = %d b = %d z = %f\n", a, b, z);   // int 나누기 int는 정수까지 표현 but 출력은 실수
    printf("2) a = %d b = %d z = %d\n", a, b, z);   // z 정수로 출력 시 자료형 불일치로 실행에러(0출력)

    c = --a + b--;  // --a + = b-- 순서로 연산
    printf("1) a = %d b = %d c = %d\n", a, b, c);
    printf("2) a = %d b = %d c = %f\n", a, b, c);   // c 실수로 출력 시 자료형 불일치로 실행에러(0.0000출력)
 
    c = a++ + ++b;   // ++b + = a++ 순서로 연산
    printf("a = %d b = %d c = %d\n", a, b, c); 

    printf("a = %d b = %d\n", ++a, ++b);    // 1 증가 후 출력
    printf("a = %d b = %d\n", a, b);    
    printf("a = %d b = %d\n", a++, b++);    // 출력 후 1 증가
    printf("a = %d b = %d\n", a, b);
    printf("a = %d b = %d\n", --a, b--);    // a는 1 감소 후 출력, b는 출력 후 1 감소
    printf("a = %d b = %d\n", a, b);
}  