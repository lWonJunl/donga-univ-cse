#pragma warning(disable: 4996)
#include <stdio.h>

int main()
{
	int n, lineCnt;

	printf("1~100 사이 정수 입력: ");
	scanf("%d", &n);

	if (n > 100) n = 100;

	lineCnt = 0;
	do {
		if (lineCnt < 10) {
			lineCnt++;
		}
		else {
			printf("\n");
			lineCnt = 1;
		}
		printf("%3d ", n--);
	} while (n > 0);
}