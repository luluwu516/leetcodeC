#include <stdbool.h>
#include <stdio.h>

int sumOfSquare(int n);
bool isHappy(int n);

int main() {
  // declaration
  int num;
  bool res;

  // input
  printf("\nEnter a number: ");
  scanf("%d", &num);

  res = isHappy(num);

  // output
  printf("\nResult:\n");
  printf("The number is a %s\n\n", (res ? "happy number" : "not happy number"));

  return 0;
}

bool isHappy(int n) {
  int sum = 0;
  while (sum != 1) {
    sum = 0;
    sum = sumOfSquare(n);
    if (sum < 10) {
      break;
    }
    n = sum;
  }
  if (sum == 1 || sum == 7) {
    return true;
  }
  return false;
}

int sumOfSquare(int n) {
  int sum = 0, digit;
  while (n > 0) {
    digit = n % 10;
    sum += digit * digit;
    n /= 10;
  }
  return sum;
}