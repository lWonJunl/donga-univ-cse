#include <stdio.h>

int main()
{
	int a = 5; 
	int b = 3; 
	int result;

	result = a * b + (++a); 
	printf("결과 = %d\n", result);

	int c = 6; 
	int d = 4;

	result = c * d + (c--); 
	printf("결과 = %d\n", result);

	return 0;
}
