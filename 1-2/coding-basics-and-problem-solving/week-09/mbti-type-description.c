#pragma warning(disable: 4996)
#include <stdio.h>

int main()
{
    char first, second; // MBTI의 첫 번째(E/I)와 두 번째(N/S) 문자를 저장할 변수
    printf("MBTI의 첫 번째와 두 번째 글자를 입력하세요 (예: E/I, N/S): ");
    scanf(" %c %c", &first, &second); 

    // 첫 번째 글자가 'E'(외향)인지 'I'(내향)인지에 따라 출력
    if (first == 'E') {
        printf("당신은 외향적인 성격을 가지고 있습니다.\n"); 
        if (second == 'S') {
            printf("감각형입니다.\n"); 
        }
        else if (second == 'N') {
            printf("직관형입니다.\n"); 
        }
    }
    else if (first == 'I') {
        printf("당신은 내향적인 성격을 가지고 있습니다.\n"); 
        if (second == 'S') {
            printf("감각형입니다.\n"); 
        }
        else if (second == 'N') {
            printf("직관형입니다.\n"); 
        }
    }

    char third, fourth; // MBTI의 세 번째(T/F)와 네 번째(J/P) 문자를 저장할 변수

    printf("MBTI의 세 번째와 네 번째 글자를 입력하세요 (예: F/T, P/J): ");
    scanf(" %c %c", &third, &fourth); 

    // 세 번째 글자가 'T'(사고형)인지 'F'(감정형)인지에 따라 출력
    if (third == 'T') {
        printf("논리적이고 객관적으로 판단하는 사고형입니다.\n"); 
        if (fourth == 'J') {
            printf("계획형입니다.\n"); 
        }
        else if (fourth == 'P') {
            printf("즉흥적입니다.\n"); 
        }
    }
    else if (third == 'F') {
        printf("감정적이고 사람 중심적으로 판단하는 감정형입니다.\n"); 
        if (fourth == 'J') {
            printf("계획형입니다.\n"); 
        }
        else if (fourth == 'P') {
            printf("즉흥적입니다.\n"); 
        }
    }
    return 0; // 프로그램 종료
}