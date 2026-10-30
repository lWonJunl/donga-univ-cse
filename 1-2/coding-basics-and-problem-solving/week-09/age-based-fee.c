#pragma warning(disable: 4996)
#include <stdio.h>

int main()
{
	int age, fee;

	printf("나이를 입력하세요: ");
	scanf("%d", &age);

	if (age <= 5) {
		fee = 0;
	}
	else if (age <= 12) {
		fee = 1000;
	}
	else if (age <= 18) {
		fee = 1500;
	}
	else if (age <= 60) {
		fee = 3000;
	}
	else {
		fee = 0;
	}
	printf("요금은: %d원\n", fee);

	return 0;
}