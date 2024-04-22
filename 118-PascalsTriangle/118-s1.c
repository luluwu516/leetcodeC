#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes);

int main() {
  // declaration
  int row, returnSize;
  int* returnColSize;
  int** res;

  // input
  printf("Enter the row: ");
  scanf("%d", &row);

  // processing
  res = generate(row, &returnSize, &returnColSize);

  // output
  printf("\n\nResult:\n");
  for (int i = 0; i < returnSize; i++) {
    for (int j = 0; j < returnColSize[i]; j++) {
      printf("%d ", res[i][j]);
    }
    puts("");
  }

  // Free memory
  for (int i = 0; i < returnSize; i++) {
    free(res[i]);
  }
  free(res);
  free(returnColSize);

  return 0;
}

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
  *returnSize = numRows;
  *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

  int** res = (int**)malloc(numRows * sizeof(int*));

  for (int i = 0; i < numRows; i++) {
    (*returnColumnSizes)[i] = i + 1;
    res[i] = (int*)malloc((i + 1) * sizeof(int));

    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i) {
        res[i][j] = 1;
      } else {
        res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
      }
    }
  }

  return res;
}