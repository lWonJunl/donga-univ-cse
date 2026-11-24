#include <stdio.h>

#define SIZE 5

int main() {
    int array[SIZE] = {4, 3, 7, 1, 5};
    int is_change = 0;

    for (int i=0; i<SIZE; i++) {
        is_change = 0; 

        for (int k=i+1; k<SIZE; k++){
            if (array[i] > array[k]) {
                int tmp = 0;

                tmp = array[i];
                array[i] = array[k];
                array[k] = tmp;
            }
        }
    } 

    for (int j = 0; j < SIZE; j++) {
        printf("%d ", array[j]);
    }
    putchar('\n');
    return 0;
}
