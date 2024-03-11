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
  int lenA = strlen(a);
  int lenB = strlen(b);
  int maxLen = lenA > lenB ? lenA : lenB;

  char* result = (char*)malloc((maxLen + 2) * sizeof(char));
  result[maxLen + 1] = '\0';
  int carry = 0;
  int indexA = lenA - 1;
  int indexB = lenB - 1;
  int indexResult = maxLen;

  while (indexA >= 0 || indexB >= 0 || carry > 0) {
    int digitA = indexA >= 0 ? a[indexA--] - '0' : 0;
    int digitB = indexB >= 0 ? b[indexB--] - '0' : 0;
    int sum = digitA + digitB + carry;
    result[indexResult--] = sum % 2 + '0';
    carry = sum / 2;
  }

  return result + (indexResult + 1);
}