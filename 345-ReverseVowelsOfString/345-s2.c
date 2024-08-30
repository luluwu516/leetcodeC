#include <ctype.h>  // tolower()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 32

// function prototype
char* reverseVowels(char* s);

int main() {
  // declaration
  char* str;
  char* res;

  // input
  str = (char*)malloc(sizeof(char) * SIZE);
  if (str == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  printf("\nEnter a string: ");
  if (fgets(str, SIZE, stdin) == NULL) {
    printf("Error reading input.\n");
    free(str);
    return 1;
  }

  // remove the newline character if it exists
  str[strcspn(str, "\n")] = '\0';
  // processing
  res = reverseVowels(str);

  // output
  printf("\nResult: \n");
  printf("Reverse only all the vowels in the string: %s\n\n", res);

  return 0;
}

char* reverseVowels(char* s) {
  int len = strlen(s);
  int indexs[len];
  char vowels[len];
  int index = 0;

  for (int i = 0; i < len; i++) {
    char c = s[i];
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' ||
        c == 'E' || c == 'I' || c == 'O' || c == 'U') {
      indexs[index] = i;
      vowels[index] = c;
      index++;
    }
  }
  for (int i = 0; i < index; i++) {
    s[indexs[i]] = vowels[index - 1 - i];
  }

  return s;
}
