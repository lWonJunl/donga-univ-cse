#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	int sum = 0;
	for (int i = 1; i <= 100; i++) {
		sum = sum + i;
		if (sum > 50) {
			printf("1부터 %d까지의 합은 %d입니다.\n", i, sum);
			break;
		}
	}
	return 0;
}