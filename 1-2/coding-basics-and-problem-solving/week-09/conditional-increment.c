#pragma warning(disable: 4996)
#include <stdio.h>

int main()
{
	int i, a = 10;

	printf("i 값 입력: ");
	scanf("%d", &i);

	if (i == 3) { 
		a++;
	}

	printf("판단 이후 a값은?: %d ", a);

	return 0;
}