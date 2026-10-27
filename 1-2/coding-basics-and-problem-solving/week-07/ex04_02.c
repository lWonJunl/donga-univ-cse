#include <stdio.h>

int main()
{
	int a = 10;
	printf("a = %d\n", a);

	int x, y, z;
	x = y = z = 20;
	printf("x = %d, y = %d, z = %d\n", x, y, z);

	int num = 5, score = 3;
	num += 3;	
	score *= 2;	
	printf("num = %d\n", num);
	printf("score = %d\n", score);

	return 0;
}