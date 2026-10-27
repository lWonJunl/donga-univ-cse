#include <stdio.h>

int main()
{
	int a = 5, b = 5;

	printf("초기상태 a: %d\n", a);
	printf("초기상태 b: %d\n", b);

	printf("전위 연산자 사용 후, a: %d\n", ++a);
	printf("후위 연산자 사용 후, b: %d\n", b++);

	printf("연산 후 결과 a: %d\n", a);
	printf("연산 후 결과 b: %d\n", b);

	return 0;
}