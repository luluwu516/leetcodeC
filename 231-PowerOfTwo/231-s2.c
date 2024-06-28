#include <stdbool.h>
#include <stdio.h>

bool isPowerOfTwo(int n);

int main() {
  // declaration
  int num;
  bool res;

  // input
  printf("\nEnter a number: ");
  scanf("%d", &num);

  res = isPowerOfTwo(num);

  // output
  printf("\nResult:\n");
  printf("The number is%s a power of two\n\n", (res ? "" : " not"));

  return 0;
}

bool isPowerOfTwo(int n) {
  if (n <= 0) {
    return false;
  }

  while (n != 1) {
    if (n % 2 == 1) {
      return false;
    }
    n /= 2;
  }

  return true;
}