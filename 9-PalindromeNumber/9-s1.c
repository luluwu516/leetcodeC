#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

  char str[20];
  sprintf(str, "%d", x);
  int len = strlen(str);

  // method 1
  //   for (int i = 0; i < len / 2; i++) {
  //     if (str[i] != str[len - i - 1]) {
  //       return 0;
  //     }
  //   }

  // method 2
  int left = len - 1;
  for (int right = 0; right < len / 2; right++) {
    if (str[right] != str[left]) {
      return 0;
    }
    left--;
  }

  return 1;
}