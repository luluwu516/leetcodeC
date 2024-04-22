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
  res[0] = (int*)malloc(sizeof(int));
  res[0][0] = 1;
  (*returnColumnSizes)[0] = 1;

  for (int row = 1; row < numRows; row++) {
    (*returnColumnSizes)[row] = row + 1;
    res[row] = (int*)malloc((row + 1) * sizeof(int));
    res[row][0] = res[row][row] = 1;

    for (int col = 1; col < row; col++) {
      res[row][col] = res[row - 1][col] + res[row - 1][col - 1];
    }
  }

  return res;
}