#pragma warning(disable: 4996)
#include <stdio.h>

int main()
{
    int sum = 0;
    int input;

    while (1) {             // 조건이 항상 참이므로 계속 반복
        printf("숫자를 입력하세요 (-1을 입력하면 종료): ");
        scanf("%d", &input);

        if (input == -1) {  // 사용자가 입력한 값이 -1인지 확인
            break;
        }
        if (input < 0) {    // 음수를 입력한 경우
            printf("음수는 제외됩니다.\n");
            continue;       // 다음 반복으로 이동
        }

        sum += input;       // 숫자를 합산
    }
    printf("입력한 숫자의 합계는 %d입니다.\n", sum);

    return 0;
}