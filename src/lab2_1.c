#include <stdio.h>

int sum_to_n(int n) {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
  }
  return sum;
}

int main(void) {
  int n;

  printf("Enter n: ");
  if (scanf("%d", &n) != 1) {
    printf("Error: Invalid input.\n");
    return 1;
  }

  if (n < 1) {
    printf("Error: n must be at least 1.\n");
  } else {
    int result = sum_to_n(n);
    printf("Sum: %d\n", result);
  }

  return 0;
}