#pragma warning(disable: 4996)
#include <stdio.h>

int main()
{
	int num;
	printf("정수를 입력하세요: ");
	scanf("%d", &num);
	// 10, 13, 16행에서는 if 문에 포함된 코드가 하나이므로 중괄호를 생략함
	if (num > 0)
		printf("%d는 양수입니다.\n", num);

	if (num < 0)
		printf("%d는 음수입니다.\n", num);

	if (num == 0)
		printf("0 입니다.\n", num);

	return 0;
}