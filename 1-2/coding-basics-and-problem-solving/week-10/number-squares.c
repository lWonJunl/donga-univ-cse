#pragma warning(disable: 4996)
#include <stdio.h>

int main()
{
	int n;

	printf("정수를 입력: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		printf("%d의 제곱: %d\n", i, i * i);
	}

	return 0;
}