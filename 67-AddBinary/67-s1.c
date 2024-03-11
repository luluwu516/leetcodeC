#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b);

int main() {
  // declaration
  char digits_a[20], digits_b[20];
  char* result;

  // input
  printf("Enter a binary number: ");
  scanf("%s", digits_a);

  printf("Enter another binary number: ");
  scanf("%s", digits_b);

  // processing
  result = addBinary(digits_a, digits_b);

  // output
  printf("\n\nResult:\n");
  printf("The sum of two binary numbers is: %s\n\n", result);

  return 0;
}

char* addBinary(char* a, char* b) {
  int i = strlen(a) - 1;
  int j = strlen(b) - 1;
  int carry = 0;
  int digitA, digitB, sum;
  int maxLength = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
  char* result = (char*)malloc(sizeof(char) * (maxLength + 2));
  int d = 0;

  while (i >= 0 || j >= 0 || carry > 0) {
    if (i >= 0) {
      digitA = (int)a[i] - '0';
    } else {
      digitA = 0;
    }

    if (j >= 0) {
      digitB = (int)b[j] - '0';
    } else {
      digitB = 0;
    }

    sum = digitA + digitB + carry;
    carry = sum / 2;
    sum = sum % 2;

    result[d] = sum + '0';

    i--;
    j--;
    d++;
  }
  result[d] = '\0';

  int left = 0, right = d - 1;
  while (left < right) {
    char temp = result[left];
    result[left] = result[right];
    result[right] = temp;
    left++;
    right--;
  }

  return result;
}