#include "stdio.h"
#include "stdlib.h"

// function prototypes
char* convertToTitle(int columnNumber);

int main() {
  // declaration
  int columnNumber;
  char* res;

  // input
  printf("\nEnter the column number: : ");
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
  char* res = (char*)calloc(10, sizeof(char));

  while (temp != 0) {
    if (temp % 26) {
      *(res + len) = (temp % 26) + 'A' - 1;
    } else {
      *(res + len) = 'Z';
      temp--;
    }
    len++;
    temp /= 26;
  }

  int right = len - 1, left = 0;
  while (left < right) {
    char temp = res[left];
    res[left] = res[right];
    res[right] = temp;
    left++;
    right--;
  }

  return res;
}