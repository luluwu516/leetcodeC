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
  int len = 0;
  int i = 0, c = 0, sum = 0;

  while (columnTitle[len] != '\0') {
    len++;
  }

  while (columnTitle[i] != '\0') {
    c = columnTitle[i] - 'A' + 1;
    int unit = 1;
    for (int j = 1; j < len; j++) {
      unit *= 26;
    }
    sum += ((len > 1) ? (c * unit) : c);
    i++;
    len--;
  }

  return sum;
}