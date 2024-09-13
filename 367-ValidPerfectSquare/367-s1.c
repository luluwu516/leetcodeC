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
  double square = sqrt(num);
  return square == (int)square;
}