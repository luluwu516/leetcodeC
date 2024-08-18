#include <stdbool.h>
#include <stdio.h>

bool isPowerOfFour(int n);

int main() {
  // declaration
  int num;
  bool res;

  // input
  printf("\nEnter a number: ");
  scanf("%d", &num);

  res = isPowerOfFour(num);

  // output
  printf("\nResult:\n");
  printf("The number is%s a power of four.\n\n", (res ? "" : " not"));

  return 0;
}

bool isPowerOfFour(int n) {
  if (n <= 0) {
    return false;
  }
  while (n % 4 == 0) {
    n /= 4;
  }
  return n == 1;
}