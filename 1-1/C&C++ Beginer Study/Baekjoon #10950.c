#include <stdio.h>

int main() {
    int loop, a, b, i=1;
    scanf("%d", &loop);
    while (i<=loop)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", a+b);
        i+=1;
    }
   
	return 0;
} 