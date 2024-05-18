#include "stdio.h"
#include "stdlib.h"

// function prototypes
char* convertToTitle(int columnNumber);

int main() {
  // declaration
  int columnNumber;
  char* res;

  // input
  printf("\nEnter the column number: ");
  scanf("%d", &columnNumber);

  // processing
  res = convertToTitle(columnNumber);

  // output
  printf("\n\nResult:\n");
  printf("The corresponding column title is '%s'\n\n", res);

  free(res);

  return 0;
}

char* convertToTitle(int columnNumber) {
  int len = 0, temp = columnNumber;
  while (temp > 0) {
    temp = (temp - 1) / 26;
    len++;
  }

  char* res = (char*)malloc(sizeof(char) * (len + 1));
  res[len] = '\0';

  temp = columnNumber;
  for (int i = len - 1; i >= 0; i--) {
    if (temp % 26) {
      res[i] = (temp % 26 - 1) + 'A';
    } else {
      res[i] = 'Z';
      temp--;
    }
    temp /= 26;
  }

  return res;
}