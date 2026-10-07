// Mert Ozari - 251ADB057
// Lab 4 - Task 1: dynamic array with malloc

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;

  printf("Enter number of elements: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("\nInvalid size.\n");
    return 1;
  }

  int* arr = malloc(n * sizeof(int));
  if (arr == NULL) {
    printf("\nMemory allocation failed.\n");
    return 1;
  }

  printf("Enter %d integers: ", n);
  long sum = 0;
  for (int i = 0; i < n; i++) {
    if (scanf("%d", &arr[i]) != 1) {
      printf("\nInvalid input.\n");
      free(arr);  // free before exiting so nothing leaks
      return 1;
    }
    sum += arr[i];
  }

  // cast to double, otherwise integer division gives 7.00 instead of 7.50
  double average = (double)sum / n;

  printf("Sum = %ld\n", sum);
  printf("Average = %.2f\n", average);

  free(arr);
  return 0;
}
