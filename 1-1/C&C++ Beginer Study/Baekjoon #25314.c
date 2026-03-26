#include <stdio.h>

int main() {
    int n, r, i;
    scanf("%d", &n);
    
    r = (n%4==0 ? n/4 : (n/4)+1);

    for(i=1;i<=r;i++) printf("%s", "long ");
    printf("%s", "int");
    

    return 0;
}