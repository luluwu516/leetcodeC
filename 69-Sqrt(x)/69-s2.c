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
  int left = 1, right = x;
  int mid, divide;

  while (left < right) {
    mid = (left + (long)right) / 2 + 1;
    divide = x / mid;
    if (divide == mid) {
      return divide;
    } else if (divide > mid) {
      left = mid;
    } else {
      right = mid - 1;
    }
  }

  return left;
}