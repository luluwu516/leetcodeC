#include <stdio.h>

int addDigits(int num);

int main() {
  // declaration
  int num, res;

  // input
  printf("\nEnter an integer: ");
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
  if (num < 10) {
    return num;
  }
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return addDigits(sum);
}