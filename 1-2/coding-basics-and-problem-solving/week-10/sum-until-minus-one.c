#pragma warning(disable: 4996)
#include <stdio.h>

int main()
{
	int sum = 0;
	int input;

	while (1) {
		printf("숫자를 입력하세요 (-1을 입력하면 종료): ");
		scanf("%d", &input);

		if (input == -1) {
			break;
		}
		sum += input;
	}
	printf("입력된 숫자의 합계는 %d입니다.\n", sum);

	return 0;
}