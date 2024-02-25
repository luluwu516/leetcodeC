#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  int len = strlen(s);
  if (len % 2 != 0) {
    return false;
  }

  int top = -1;

  char* stack = (char*)malloc(sizeof(char) * len);
  for (int i = 0; i < len; i++) {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
      top++;
      stack[top] = s[i];
    } else {
      if (((top == -1) || s[i] == ')' && stack[top] != '(') ||
          (s[i] == ']' && stack[top] != '[') ||
          (s[i] == '}' && stack[top] != '{')) {
        free(stack);
        return false;
      } else {
        top--;
      }
    }
  }
  free(stack);

  return top == -1;
}