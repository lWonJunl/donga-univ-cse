#include <stdio.h>

int main()
{
	int a = 15, b = 4;

	int sum = a + b; // 정수 범위 덧셈
	int difference = a - b; // 정수 범위 뺄셈
	int product = a * b; // 정수 범위 곱셈
	int quotient = a / b; // 정수 범위 나눗셈

	printf("sum: %d\n", sum);
	printf("difference: %d\n", difference);
	printf("product: %d\n", product);
	printf("quotient: %d\n", quotient);

	float x = 5.5, y = 2.3;

	float floatSum = x + y; // 부동 소수점 덧셈
	float floatDifference = x - y; // 부동 소수점 뺄셈
	float floatProduct = x * y; // 부동 소수점 곱셈
	float floatQuotient = x / y; // 부동 소수점 나눗셈

	printf("floatSum: %f\n", floatSum);
	printf("floatDifference: %f\n", floatDifference);
	printf("floatProduct: %f\n", floatProduct);
	printf("floatQuotient: %f\n", floatQuotient);

	return 0;
}