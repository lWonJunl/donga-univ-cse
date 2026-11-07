#pragma warning(disable: 4996)
#include <stdio.h>

int main()
{
	int n = 0, sum = 0;

	printf("정수 입력(종료: Ctrl+Z): \n");

	while (scanf("%d", &n) != EOF) {
		sum = sum + n;
	}
	printf("\n합계: %d\n", sum);

	return 0;
}