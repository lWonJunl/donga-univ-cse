#include <stdio.h>

extern int sharedVar; // 외부 연결 변수 사용 선언 

void displaySharedVar(void); // 외부 연결 함수 선언

int main()
{
	printf("내부 변수 sharedVar: %d\n", sharedVar);
	displaySharedVar();
	return 0;
}