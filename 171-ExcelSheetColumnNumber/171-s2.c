#include "stdio.h"
#include "stdlib.h"

int titleToNumber(char* columnTitle);

int main() {
  // declaration
  char columnTitle[8];
  int res;

  // input
  printf("\nEnter the column title: ");
  scanf("%s", columnTitle);

  // processing
  res = titleToNumber(columnTitle);

  // output
  printf("\n\nResult:\n");
  printf("The column number is '%d'\n\n", res);

  return 0;
}

int titleToNumber(char* columnTitle) {
  int sum = 0;
  for (int i = 0; columnTitle[i] != '\0'; i++) {
    sum = sum * 26 + (columnTitle[i] - 'A' + 1);
  }

  return sum;
}