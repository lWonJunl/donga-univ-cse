#include <stdio.h>
int main() 
{
	int mainVar = 5; // main() 함수의 지역변수
	printf("main 함수의 초기 mainVar = %d\n", mainVar);

	{
		int blockVar = 10; // 중첩 블록의 지역변수
		printf("블록 안에서 blockVar = %d\n", blockVar);

		mainVar = 20; // main() 함수의 지역변숫값 변경
		printf("블록 안에서 변경된 mainVar = %d\n", mainVar);
	}

	printf("블록 바깥에서 mainVar = %d\n", mainVar);

	return 0;
}