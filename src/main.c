// #include <stdio.h>
#include "generated_array.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//  helper macro to print the array contents for debugging
#define PRINT_ARRAY(arr, length)                                               \
  do {                                                                         \
    printf("Array elements: ");                                                \
    for (int i = 0; i < length; i++) {                                         \
      printf("%d ", arr[i]);                                                   \
    }                                                                          \
    printf("\n");                                                              \
  } while (0)

int compare_integers(const void *a, const void *b);

//  DO NOT INPUT A BLOCK SIZE THAT WILL RESULT IN A CHUNK THAT IS LESS THAN THE
//  BLOCK SIZE, DO NOT!!
void block_sort(uint8_t *array, size_t array_size, size_t block_size);
void insertion_sort(uint8_t *arr, int N);

int main(void) {
  // The baseline, q sort.
  // qsort(generated_array, ARRAY_SIZE, sizeof(uint8_t), compare_integers);

  block_sort(generated_array, ARRAY_SIZE, 400);

  // PRINT_ARRAY(generated_array, ARRAY_SIZE);
  // decomment if you want to debug the thingy.
}

int compare_integers(const void *a, const void *b) {
  return (*(const uint8_t *)a - *(const uint8_t *)b);
}

void insertion_sort(uint8_t *arr, int N) {

  for (int i = 1; i < N; i++) {
    uint8_t key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

//  SORTING FUNCTIONS IMPLEMENTED IN THIS PROJECT SHOULD BE 100% SELF
//  CONTAINED!!!!! >:o
void block_sort(uint8_t *array, size_t array_size, size_t block_size) {
  const size_t block_num = array_size / block_size;

  int i = 0;
  while (++i < (int)block_num) {
    insertion_sort(array + ((size_t)i * block_size), (int)block_size);
  }

  // TODO:
  // stable and in-place Merging
}
