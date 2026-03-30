#include <stdio.h>
#include <string.h>

int main(){
    int n, i, len;
    char str[20];
    scanf("%d", &n);

    for(i=1; i<=n; i++){
        scanf("%s", &str);
        len = strlen(str);

        if (len>=6 && len<=9) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}
