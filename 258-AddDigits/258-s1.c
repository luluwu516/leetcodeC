#include <stdio.h>

int addDigits(int num);

int main() {
  // declaration
  int num, res;

  // input
  printf("\nEnter a string: ");
  scanf("%d", &num);

  // processing
  res = addDigits(num);

  // output
  printf(
      "\nAfter repeatedly adding all its digits until the result has only one "
      "digit:");
  printf("Result: %d\n\n", res);

  return 0;
}

int addDigits(int num) {
  if (num == 0) {
    return 0;
  } else if (num % 9 == 0) {
    return 9;
  } else {
    return num % 9;
  }
}