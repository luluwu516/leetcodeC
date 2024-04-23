#include <stdio.h>
#include <stdlib.h>

int* getRow(int rowIndex, int* returnSize);

int main() {
  // declaration
  int row, returnSize;
  int* res;

  // input
  printf("Enter the row: ");
  scanf("%d", &row);

  // processing
  res = getRow(row, &returnSize);

  // output
  printf("\n\nResult:\n");
  for (int i = 0; i < returnSize; i++) {
    printf("%d ", res[i]);
  }
  puts("");

  // Free memory
  free(res);

  return 0;
}

int* getRow(int rowIndex, int* returnSize) {
  *returnSize = rowIndex + 1;
  int* row = (int*)malloc((*returnSize) * sizeof(int));
  *row = 1;

  for (int i = 1; i < (*returnSize); i++) {
    *(row + i) = (long)*(row + i - 1) * ((*returnSize) - i) / i;
  }

  return row;
}