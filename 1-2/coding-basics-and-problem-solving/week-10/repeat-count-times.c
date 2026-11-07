#pragma warning(disable: 4996)
#include <stdio.h>

int main()
{
	int i, limit;

	printf("반복 횟수를 입력: ");
	scanf("%d", &limit);

	for (i = 1; i <= limit; i++) {
		printf(" %d \n", i);
	}

	return 0;
}