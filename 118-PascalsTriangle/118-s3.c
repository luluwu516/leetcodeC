#include <stdio.h>
#include <stdlib.h>

int* generateRow(int row);
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
  for (int i = 1; i <= numRows; i++) {
    int* tempArray = generateRow(i);
    res[i - 1] = tempArray;
    (*returnColumnSizes)[i - 1] = i;
  }

  return res;
}

int* generateRow(int row) {
  int val = 1;
  int* newRow = (int*)malloc(sizeof(int) * row);

  newRow[0] = 1;

  for (int col = 1; col < row; col++) {
    val = val * (row - col);
    val = val / col;
    newRow[col] = val;
  }

  return newRow;
}