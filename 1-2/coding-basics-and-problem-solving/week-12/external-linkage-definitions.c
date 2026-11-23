#include <stdio.h>

int sharedVar = 10; // 외부 연결 변수 정의

void displaySharedVar(void) { // 외부 연결 함수 정의
	sharedVar += 5;
	printf("외부 공유 변수: %d\n", sharedVar);
}