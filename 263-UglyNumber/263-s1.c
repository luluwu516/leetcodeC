#include <stdbool.h>
#include <stdio.h>

bool isUgly(int n);

int main() {
  // declaration
  int num;
  bool res;

  // input
  printf("\nEnter an integer: ");
  scanf("%d", &num);

  // processing
  res = isUgly(num);

  // output
  printf("Result: \n\n");
  printf("The integer is%s a ugly number", (res ? "" : " not"));

  return 0;
}

bool isUgly(int n) {
  if (n <= 0) {
    return false;
  } else if (n == 1) {
    return true;
  } else if (n % 2 == 0) {
    return isUgly(n / 2);
  } else if (n % 3 == 0) {
    return isUgly(n / 3);
  } else if (n % 5 == 0) {
    return isUgly(n / 5);
  } else {
    return false;
  }
}