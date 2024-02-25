// This solution will cause "ERROR: AddressSanitizer: heap-buffer-overflow" on
// Leetcode since I access memory beyond the bounds of the array s.
#include <stdbool.h>
#include <stdio.h>

bool isValid(char* s);

int main() {
  // declaration
  char strs[120];

  // input
  printf("Enter parentheses, such as '(', ')', '{', '}', '[' or ']': ");
  scanf("%s", strs);

  // Processing and Output
  if (isValid(strs)) {
    printf("\nThe parentheses is vaild.\n");
  } else {
    printf("\nThe parentheses is invaild.\n");
  }

  return 0;
}

bool isValid(char* s) {
  char* stPtr = s;
  if (*stPtr == '\0') return true;
  stPtr--;
  *stPtr = '0';

  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
      stPtr++;
      stPtr = &s[i];
    } else {
      if (*stPtr == '0') {
        return false;
      } else if (s[i] == ')' && *stPtr == '(') {
        stPtr--;
      } else if (s[i] == ']' && *stPtr == '[') {
        stPtr--;
      } else if (s[i] == '}' && *stPtr == '{') {
        stPtr--;
      } else {
        return false;
      }
    }
  }

  return *stPtr == '0';
}