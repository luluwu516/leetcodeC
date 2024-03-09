#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize);

int main() {
  // declaration
  int size;
  int* result;
  int returnSize = 0;

  // input
  printf("\nEnter the number of the digits: ");
  scanf("%d", &size);

  int digits[size];

  printf("Enter list digits:\n");
  for (int i = 0; i < size; i++) {
    printf("> ");
    scanf("%d", &digits[i]);
  }

  // processing
  result = plusOne(digits, size, &returnSize);

  // output
  if (result == NULL) {
    printf("No plus one solution\n");
  } else {
    printf("\nResult:\nThe number of the digits plus one is: [ ");
    for (int i = 0; i < returnSize; i++) {
      printf("%d ", result[i]);
    }
    printf("] \n\n");
  }

  return 0;
}

int* plusOne(int* digits, int digitsSize, int* returnSize) {
  *returnSize = digitsSize;
  for (int i = digitsSize - 1; i >= 0; i--) {
    if (digits[i] < 9) {
      digits[i]++;
      return digits;
    }
    digits[i] = 0;
  }

  (*returnSize)++;
  int* result = (int*)malloc((*returnSize) * sizeof(int));
  if (result == NULL) {
    return NULL;
  }
  result[0] = 1;
  for (int i = 1; i < *returnSize; i++) {
    result[i] = digits[i - 1];
  }

  return result;
}