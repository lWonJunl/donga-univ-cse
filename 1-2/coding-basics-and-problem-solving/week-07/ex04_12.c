#include <stdio.h>

int main()
{
	int a = 0x5555, b = 0x00ff;

	printf("a = %x, b = %x\n", a, b);
	printf("~a = %x, ~b = %x\n", ~a, ~b); // 비트 NOT 연산
	printf("a & b = %x\n", a & b); // 비트 AND 연산
	printf("a | b = %x\n", a | b); // 비트 OR 연산
	printf("a ^ b = %x\n", a ^ b); // 비트 XOR 연산

	return 0;
}