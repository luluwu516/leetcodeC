#include <stdio.h>

// function prototype
int isPalindrome(int x);

int main() {
  // declaraction
  int num;

  // input
  printf("Enter an integer: ");
  scanf("%d", &num);

  // processing and output
  printf("\nResult: ");
  if (isPalindrome(num)) {
    printf("%d is a Palindrome Number.\n", num);
  } else {
    printf("%d is not a Palindrome Number.\n", num);
  }

  return 0;
}

int isPalindrome(int x) {
  if (x < 0) {
    return 0;
  } else if (x < 10) {
    return 1;
  }

  long temp = x;
  long reversed = 0;
  int dig;

  while (temp != 0) {
    dig = temp % 10;
    reversed = reversed * 10 + dig;
    temp /= 10;
  }

  return x == reversed;
}