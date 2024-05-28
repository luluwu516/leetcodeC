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
  int slow = sumOfSquare(n);
  int fast = sumOfSquare(sumOfSquare(n));
  while (fast != 1 && fast != slow) {
    slow = sumOfSquare(slow);
    fast = sumOfSquare(sumOfSquare(fast));
  }
  return fast == 1;
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