#include <stdio.h>

int main() {
    int a, b, c,reward;
    scanf("%d %d %d", &a, &b, &c);

    if (a == b && b == c)
    {
        reward = 10000+a*1000;
    } else if (a == b || b == c || a == c)
    {
        reward = 1000+(a == b ? a : (b == c ? b : c))*100;
    } else if (a != b && b != c && a != c)
    {
        reward = 100*(a > b ? (a > c ? a : c) : (b > c ? b : c));
    }
    
    printf("%d", reward);
    
	return 0;
}