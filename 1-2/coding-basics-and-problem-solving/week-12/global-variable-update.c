#include <stdio.h>

int globalVar = 10;

void printValue() {
	printf("globalVar = %d\n", globalVar);
}

int main()
{
	printValue();
	globalVar = 20;
	printValue();

	return 0;
}