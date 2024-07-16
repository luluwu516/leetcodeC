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
  }
  while (n % 2 == 0) {
    n /= 2;
  }
  while (n % 3 == 0) {
    n /= 3;
  }
  while (n % 5 == 0) {
    n /= 5;
  }
  return n == 1;
}