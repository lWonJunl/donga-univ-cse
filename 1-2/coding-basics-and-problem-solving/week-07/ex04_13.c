#include <stdio.h>

int main()
{
	int a = 30;

	// 왼쪽으로 1비트씩 이동할 때마다 값이 2배가 됨
	printf("a << 1 = %d\n", a << 1);
	printf("a << 2 = %d\n", a << 2);
	printf("a << 3 = %d\n", a << 3);
	printf("a << 4 = %d\n", a << 4);

	return 0;
}