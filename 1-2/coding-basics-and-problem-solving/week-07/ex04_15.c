#include <stdio.h>

int main()
{
	int a = 5;
	int b = 10;
	int c = 5;

	// == 연산자와 > 연산자는 && 연산자보다 우선순위가 높다.
	int result = a == c && b > a;
	printf("Result: %d\n", result); // 출력: 1 (true)

	return 0;
}