#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
  char* arr;
  int top;
  int size;
} Stack;

bool isFull(Stack* stack);
bool isEmpty(Stack* stack);
void push(Stack* stack, char item);
char pop(Stack* stack);
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

Stack* createStack(int size) {
  Stack* stack = (Stack*)malloc(sizeof(Stack));
  stack->size = size;
  stack->top = -1;
  stack->arr = (char*)malloc(stack->size * sizeof(char));
  return stack;
}

bool isFull(Stack* stack) { return stack->top == stack->size - 1; }

bool isEmpty(Stack* stack) { return stack->top == -1; }

void push(Stack* stack, char item) {
  if (isFull(stack)) return;
  stack->arr[++stack->top] = item;
}

char pop(Stack* stack) {
  if (isEmpty(stack)) return '\0';
  return stack->arr[stack->top--];
}

bool isValid(char* s) {
  int len = strlen(s);
  Stack* stack = createStack(len);
  for (int i = 0; i < len; i++) {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
      push(stack, s[i]);
    } else {
      if (isEmpty(stack)) return false;
      char top_char = pop(stack);
      if ((s[i] == ')' && top_char != '(') ||
          (s[i] == ']' && top_char != '[') ||
          (s[i] == '}' && top_char != '{')) {
        return false;
      }
    }
  }
  return isEmpty(stack);
}