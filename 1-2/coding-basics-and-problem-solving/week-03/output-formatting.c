#include <stdio.h>

int main(void){
    printf("%10c\n", 'a');
    printf("%10d\n", 128);
    printf("%-10d\n", 128);
    printf("%10.3f\n", 3.141592);
    printf("%10.4s\n", "Love is");
    return 0;
}