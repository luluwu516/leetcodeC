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
  int** tri = (int**)malloc((*returnSize) * sizeof(int*));

  for (int i = 0; i < (*returnSize); i++) {
    tri[i] = (int*)malloc((i + 1) * sizeof(int));

    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i) {
        tri[i][j] = 1;
      } else {
        tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
      }
    }
  }

  return tri[rowIndex];
}