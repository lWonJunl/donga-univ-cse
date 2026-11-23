#include <stdio.h>

// 팩토리얼을 계산하는 재귀 함수
int factorial(int n) {
	if (n <= 1) {
		return 1; // n이 1 이하인 경우 1을 반환
	}
	else {
		return n * factorial(n - 1); // 재귀 호출 factorial (n-1)
	}
}
int main() {
	int number = 7;

	printf("%d! = %d\n", number, factorial(number));

	return 0;
}