#include <stdio.h>

#define PI 3.14159265

int main()
{
	float radius = 5.0f;
	float area = 0;

	area = PI * radius * radius;

	printf("반지름 : %.2f\n", radius);
	printf("기호 상수 PI : %.8f\n", PI);
	printf("원의 넓이: %.8f\n", area);

	return 0;
}