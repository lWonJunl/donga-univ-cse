#include <stdio.h>

int main()
{
	int num = 10;

	printf("num 변수의 초기 상태 값: %d\n", num);

	num += 5; // num = num + 5;
	printf("num += 5 연산 후: %d\n", num);

	num -= 3; // num = num - 3;
	printf("num -= 3 연산 후: %d\n", num);

	num *= 4; // num = num * 4;
	printf("num *= 4 연산 후: %d\n", num);

	num /= 2; // num = num / 2;
	printf("num /= 2 연산 후: %d\n", num);

	num %= 7; // num = num % 7;
	printf("num %%= 7 연산 후: %d\n", num); 
	
	return 0;
}