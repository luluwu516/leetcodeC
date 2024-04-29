#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define SIZE 200000

bool isPalindrome(char* s);

int main() {
  // declaration
  char s[SIZE];
  bool res;

  // input
  printf("\nEnter a string: ");
  fgets(s, SIZE, stdin);

  res = isPalindrome(s);

  // output
  printf("\nResult:\n");
  printf("The string is a %s\n\n", (res ? "palindrome" : "not palindrome"));

  return 0;
}

bool isPalindrome(char* s) {
  int left = 0, right = strlen(s) - 1;

  while (left < right) {
    while (!isalnum(s[left]) && (left < right)) {
      left++;
    }
    while (!isalnum(s[right]) && (left < right)) {
      right--;
    }
    if (tolower(s[left]) != tolower(s[right])) {
      return false;
    }

    left++;
    right--;
  }

  return true;
}