#include <stdio.h>

int main()
{
	int a = 10;
	int b = 20;

	printf("a == b: %d\n", a == b); // a와 b가 같은지 확인
	printf("a != b: %d\n", a != b); // a와 b가 다른지 확인
	printf("a > b: %d\n", a > b);   // a가 b보다 큰지 확인
	printf("a < b: %d\n", a < b);   // a가 b보다 작은지 확인
	printf("a >= b: %d\n", a >= b); // a가 b보다 크거나 같은지 확인
	printf("a <= b: %d\n", a <= b); // a가 b보다 작거나 같은지 확인

	return 0;
}