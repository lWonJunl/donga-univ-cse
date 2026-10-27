#include <stdio.h>

int main()
{
	int maxV, minV;
	int a = 900, b = 800;

	maxV = (a > b) ? a : b; // a가 b보다 크면 maxV에 a 값을 대입, 그렇지 않으면 b 값을 대입
	minV = (a < b) ? a : b; // a가 b보다 작으면 minV에 a 값을 대입, 그렇지 않으면 b 값을 대입

	printf("900과 800 중에 더 큰 수: %d\n", maxV);
	printf("900과 800 중에 더 작은 수: %d\n", minV);

	return 0;
}