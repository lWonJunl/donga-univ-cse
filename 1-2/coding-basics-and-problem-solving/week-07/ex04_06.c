#include <stdio.h>

int main()
{
	int a = 5, b = 5;
	int re1 = 0, re2 = 0;

	printf("초기상태 a: %d, b: %d\n", a, b);
	printf("초기상태 re1: %d, re2: %d\n", re1, re2);

	++a;
	re1 = a;
	re2 = b++; // b의 값을 re2에 대입한 후 b의 값을 1 증가시킴

	printf("연산 후 결과 a: %d, b: %d\n", a, b);
	printf("연산 후 결과 re1: %d, re2: %d\n", re1, re2);

	return 0;
}