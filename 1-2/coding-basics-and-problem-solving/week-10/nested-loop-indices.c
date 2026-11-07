#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	int i, j;
	for (i = 0; i < 3; i++) {			// 외부 반복문
		for (j = 0; j < 3; j++) {		// 내부 반복문
			printf("[%d, %d] ", i, j); // 배열의 인덱스 출력
		}
		printf("\n"); // 한 행을 출력한 후 줄 바꿈
	}
	return 0;
}