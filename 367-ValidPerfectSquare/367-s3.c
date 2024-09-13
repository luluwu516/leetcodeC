#include <math.h>
#include <stdbool.h>
#include <stdio.h>

// function prototype
bool isPerfectSquare(int num);

int main() {
  // declaration
  int num;
  bool res;

  // input
  printf("\nEnter a number: ");
  scanf("%d", &num);

  // processing
  res = isPerfectSquare(num);

  // output
  printf("\nResult: \n");
  printf("%d is %sa perfect square\n\n", num, (res ? "" : "not "));

  return 0;
}

bool isPerfectSquare(int num) {
  int low = 0, high = num;
  while (low <= high) {
    long mid = low + (high - low) / 2;
    long square = mid * mid;
    if (square == num) {
      return true;
    } else if (square > num) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return false;
}