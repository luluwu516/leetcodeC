#include <stdio.h>
#include <stdlib.h>

int* countBits(int n, int* returnSize);

int main() {
  // declaration
  int num, size;
  int* res;

  // input
  printf("\nEnter an integer: ");
  scanf("%d", &num);

  res = countBits(num, &size);

  // output
  printf("\nResult:\n");
  for (int i = 0; i < size; i++) {
    printf("%d ", *(res + i));
  }
  puts("\n");

  return 0;
}

int* countBits(int n, int* returnSize) {
  *returnSize = n + 1;
  int* res = (int*)malloc(sizeof(int) * (n + 1));
  res[0] = 0;
  for (int i = 1; i < n + 1; i++) {
    res[i] = 1 + res[i & (i - 1)];
  }
  return res;
}