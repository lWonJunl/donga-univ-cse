#include <stdio.h>
#include <string.h>

int main(void) {
    int va = 0;
    char re[10] = {' '};

    if (va >= 90) {
        strcpy(re, "합격");
    } else if (va >= 80) {
        strcpy(re, "통과");
    } else if (va >= 70) {
        strcpy(re, "보통");
    } else {
        strcpy(re, "불합격");
    }

    printf("%d점은 %s이다.\n", va, re);
    return 0;
}