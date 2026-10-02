#include <stdio.h>

int main()
{
	int maxInt = 2147483647;
	int overflow1 = maxInt + 1;

	printf("maxInt: %d\n", maxInt);
	printf("overflow1: %d\n", overflow1);

	unsigned int maxUint = 4294967295U;
	unsigned int overflow2 = maxUint + 1;

	printf("maxUint: %u\n", maxUint);
	printf("overflow2: %u\n", overflow2);

	return 0;
}