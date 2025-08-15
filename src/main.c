/*
  SORTING A BIG AF ARRAY!!!! (10million items specifically) SORTING FUNCTIONS
  IMPLEMENTED IN THIS PROJECT SHOULD BE 100% SELF CONTAINED!!!!! >:o
 */

#include "generated_array.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINT_ARRAY(arr, length)                                               \
  do {                                                                         \
    printf("Array elements: ");                                                \
    for (size_t i = 0; i < (size_t)(length); i++) {                            \
      printf("%u ", (unsigned)(arr)[i]);                                       \
    }                                                                          \
    printf("\n");                                                              \
  } while (0)

static void counting_sort_u8(uint8_t *arr, size_t n);

int main(void) {
  counting_sort_u8(generated_array, ARRAY_SIZE);

  // PRINT_ARRAY(generated_array, ARRAY_SIZE);
  return 0;
}

static void counting_sort_u8(uint8_t *restrict arr, size_t n) {
  size_t counts[256];
  memset(counts, 0, sizeof(counts));

  size_t i = 0;
  for (; i + 31 < n; i += 32) {
    counts[arr[i + 0]]++;
    counts[arr[i + 1]]++;
    counts[arr[i + 2]]++;
    counts[arr[i + 3]]++;
    counts[arr[i + 4]]++;
    counts[arr[i + 5]]++;
    counts[arr[i + 6]]++;
    counts[arr[i + 7]]++;
    counts[arr[i + 8]]++;
    counts[arr[i + 9]]++;
    counts[arr[i + 10]]++;
    counts[arr[i + 11]]++;
    counts[arr[i + 12]]++;
    counts[arr[i + 13]]++;
    counts[arr[i + 14]]++;
    counts[arr[i + 15]]++;
    counts[arr[i + 16]]++;
    counts[arr[i + 17]]++;
    counts[arr[i + 18]]++;
    counts[arr[i + 19]]++;
    counts[arr[i + 20]]++;
    counts[arr[i + 21]]++;
    counts[arr[i + 22]]++;
    counts[arr[i + 23]]++;
    counts[arr[i + 24]]++;
    counts[arr[i + 25]]++;
    counts[arr[i + 26]]++;
    counts[arr[i + 27]]++;
    counts[arr[i + 28]]++;
    counts[arr[i + 29]]++;
    counts[arr[i + 30]]++;
    counts[arr[i + 31]]++;
  }
  for (; i < n; ++i) {
    counts[arr[i]]++;
  }

  size_t offset = 0;
  for (unsigned v = 0; v < 256; ++v) {
    size_t c = counts[v];
    if (c) {
      memset(arr + offset, (int)v, c);
      offset += c;
    }
  }
}
