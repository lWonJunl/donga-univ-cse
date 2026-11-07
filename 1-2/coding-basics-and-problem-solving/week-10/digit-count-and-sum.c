#pragma warning(disable: 4996)
#include <stdio.h>

int main()
{
	int number, count = 0, sum = 0;

	printf("\n정수 입력: ");
	scanf("%d", &number);
	printf("처음에 입력한 수: %d\n\n", number);

	while (number != 0) {
		count++;
		sum += number % 10;
		number /= 10;
	}
	printf("입력한 수의 자릿수 개수: %d\n", count);
	printf("입력한 수의 각 자릿수의 합계: %d\n", sum);

	return 0;
}