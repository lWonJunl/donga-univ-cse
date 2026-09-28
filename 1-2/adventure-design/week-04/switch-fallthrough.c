#include <stdio.h>

int main() {
    int option = 0;
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("서울\n");
        case 2:
            printf("부산\n");
        default: 
            printf("대구");
    }
}