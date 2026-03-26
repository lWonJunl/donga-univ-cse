#include <stdio.h>

int main() {
    int a, b, c, m=0, h=0;
    scanf("%d %d", &a, &b);
    scanf("%d", &c);

    b += c;
    m = b%60;
    h = a+(b/60);
    
    if (h>23) h -= 24;
    
    printf("%d %d", h, m);
    
	return 0;
}