#include <stdio.h>
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
  int count = 0;
  int lastWordCount = 0;
  int i = 0;

  while (s[i] != '\n') {  // we use fgets() in main, so I set '\n' as a flag
    if (s[i] != ' ') {
      count++;
      lastWordCount = count;
    } else {
      count = 0;
    }
    i++;
  }
  return lastWordCount;
}