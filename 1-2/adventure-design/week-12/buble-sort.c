#include <stdio.h>

#define SIZE 5

int main() {
    int array[SIZE] = {4, 3, 7, 1, 5};
    int is_change = 0;

    for (int i=0; i<SIZE-1; i++) {
        is_change = 0;   

        for (int k=0; k<SIZE-1-i; k++){
            if (array[k] > array[k+1]) {
                int tmp = 0;

                tmp = array[k];
                array[k] = array[k+1];
                array[k+1] = tmp;

                is_change = 1;
            }
        }

        if (!is_change) break;
    } 

    for (int j = 0; j < SIZE; j++) {
        printf("%d ", array[j]);
    }
    putchar('\n');
    return 0;
}
