#include <stdbool.h>
#include <stdio.h>

bool isPowerOfThree(int n);

int main() {
  // declaration
  int num;
  bool res;

  // input
  printf("\nEnter a number: ");
  scanf("%d", &num);

  res = isPowerOfThree(num);

  // output
  printf("\nResult:\n");
  printf("The number is%s a power of three.\n\n", (res ? "" : " not"));

  return 0;
}

bool isPowerOfThree(int n) {
  if (n <= 0) {
    return false;
  }

  while (n != 1) {
    if (n % 3 != 0) {
      return false;
    }
    n /= 3;
  }

  return true;
}