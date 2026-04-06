#include <stdio.h>

int main() {
    int n, i, j, k;
    scanf("%d", &n);

  for(i=1; i <=n; i++){
    for(k=0; k<=(n-i)-1; k++){
      printf(" ");
    }
    for(j=1; j<=i; j++){
      printf("*");
    }
    printf("\n");
  }

  return 0;
  
}
