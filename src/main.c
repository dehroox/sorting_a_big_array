//#include <stdio.h>
#include <stdlib.h>
#include "generated_array.h"

#define PRINT_ARRAY(arr, length) \
    do { \
        printf("Array elements: "); \
        for (int i = 0; i < length; i++) { \
            printf("%d ", arr[i]); \
        } \
        printf("\n"); \
    } while(0)

int compare_integers(const void *a, const void *b);

int main(void) {
    qsort(generated_array, ARRAY_SIZE, sizeof(uint8_t), compare_integers);
    // PRINT_ARRAY(generated_array, ARRAY_SIZE);
    // decomment if you want to debug the thingy.
}

int compare_integers(const void *a, const void *b) {
    return (*(const uint8_t*)a - *(const uint8_t*)b);
}
