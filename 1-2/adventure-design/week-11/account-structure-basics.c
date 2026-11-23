#include <stdio.h>
#include <string.h>

struct account {
    char name[12];
    int actnum;
    double balance;
};

int main() {
    struct account mine = {"홍길동", 1001, 300000};
    struct account yours;

    printf("%s %d %.2f\n", mine.name, mine.actnum, mine.balance);

    strcpy(yours.name, "이동원");
    yours.actnum = 1002;
    yours.balance = 500000;

    printf("구조체 크기: %zu\n", sizeof(mine));
    printf("%s %d %.2f\n", yours.name, yours.actnum, yours.balance);

    return 0;    
}