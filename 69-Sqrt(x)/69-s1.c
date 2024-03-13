#include <stdio.h>

int mySqrt(int x);

int main() {
  // declaration
  int num, result;

  // input
  printf("\nEnter a number: ");
  scanf("%d", &num);

  result = mySqrt(num);

  // output
  printf("\n\nResult:\n");
  printf("The square root of %d is %d\n\n", num, result);

  return 0;
}

int mySqrt(int x) {
  if (x <= 1) {
    return x;
  }
  int i;
  for (i = 1; i < x; i++) {
    if (x / i < i) {
      return i - 1;
    }
  }
  return i - 1;
}