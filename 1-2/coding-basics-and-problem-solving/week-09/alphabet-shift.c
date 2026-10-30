#pragma warning(disable: 4996)
#include <stdio.h>
#include <ctype.h>

int main()
{
	char ch;
	printf("알파벳을 입력하세요: ");
	scanf(" %c", &ch);

	if (ch >= 'a' && ch <= 'z') {
		ch = (ch - 'a' + 3) % 26 + 'a';
	}
	else {
		ch = (ch - 'A' + 3) % 26 + 'A';
	}

	printf("변경된 문자: %c\n", ch);

	return 0;
}