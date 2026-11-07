#pragma warning(disable: 4996)
#include <stdio.h>

int main()
{
	int score;
	char choice;

	do {
		printf("점수를 입력하세요 (0~100): ");
		scanf("%d", &score);

		if (score >= 90) {
			printf("학점: A\n");
		}
		else if (score >= 80) {
			printf("학점: B\n");
		}
		else if (score >= 70) {
			printf("학점: C\n");
		}
		else if (score >= 60) {
			printf("학점: D\n");
		}
		else {
			printf("학점: F\n");
		}

		printf("다른 점수를 입력하시겠습니까? (Y/N): ");
		scanf(" %c", &choice);

	} while (choice == 'Y' || choice == 'y');

	return 0;
}