#include <stdio.h>
#include <string.h>
#define SIZE 100

int lengthOfLastWord(char* nums);

int main() {
  // declaration
  char string[SIZE];
  int result;

  // input
  printf("\nEnter a string: ");
  fgets(string, SIZE, stdin);

  result = lengthOfLastWord(string);

  // output
  printf("\nResult:\n");
  printf("The length of the last word is %d\n\n", result);

  return 0;
}

int lengthOfLastWord(char* s) {
  int current = strlen(s) - 1;
  int count = 0;

  while (s[current] == ' ' || s[current] == '\n') {
    current--;
  }
  // "current >= 0" has to be the first condition
  while (current >= 0 && s[current] != ' ') {
    count++;
    current--;
  }
  return count;
}