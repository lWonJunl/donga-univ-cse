#include <stdio.h>

int main()
{
	int a = 52, b = 31, c = 15;
	int res1, res2, res3; // 결괏값을 저장할 변수 선언

	res1 = a < b && b < c;
	printf("a는 b보다 작고, b는 c보다 작습니다.\n");
	printf("a < b && b < c -> %d\n", res1);

	res2 = a < b || a > c;
	printf("a는 b보다 작거나, a는 c보다 큽니다.\n");
	printf("a < b || a > c -> %d\n", res2);

	res3 = !(a < b);
	printf("a는 b보다 작습니다.\n");
	printf("!(a < b) -> %d\n", res3);

	return 0;
}