#include <stdio.h>

void show() {
	auto int num = 5; // 'int num = 5;'으로도 작성 가능
	printf("Auto Num: %d\n", num);
}

int main()
{
	show();
	return 0;
}