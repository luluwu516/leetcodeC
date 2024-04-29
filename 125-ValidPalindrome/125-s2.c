#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define SIZE 200000

bool ischar(char s);
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
    if (!ischar(s[left]))
      left++;
    else if (!ischar(s[right]))
      right--;
    else {
      if (tolower(s[left]) == tolower(s[right])) {
        left++;
        right--;
      } else
        return false;
    }
  }

  return true;
}

bool ischar(char s) {
  return (((s >= 'a') && (s <= 'z')) || ((s >= 'A') && (s <= 'Z')) ||
          ((s >= '0') && (s <= '9')));
}