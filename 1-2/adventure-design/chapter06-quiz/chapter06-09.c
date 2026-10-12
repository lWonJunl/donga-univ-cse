#include <stdio.h>

int main() {
    int year = 0, month = 0;
   
    printf("년과 월을 다음과 같이 입력하면 그 달의 말일을 알려드립니다.\n");
    printf("2003 2 : 입력 >> ");
    scanf(" %d %d", &year, &month);

    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            printf("%d년 %d월의 말일은 31일입니다.\n", year, month);
            break;
        case 4: case 6: case 9: case 11:
            printf("%d년 %d월의 말일은 30일입니다.\n", year, month);
            break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                printf("%d년 %d월의 말일은 29일입니다.\n", year, month);
            } else {
                printf("%d년 %d월의 말일은 28일입니다.\n", year, month);
            }
            break;
    }
    
    return 0;
}
