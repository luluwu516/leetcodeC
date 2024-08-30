#include <ctype.h>  // tolower()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 32

// function prototype
int isVowel(char c);
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

int isVowel(char c) {
  c = tolower(c);
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

char* reverseVowels(char* s) {
  int left = 0, right = strlen(s) - 1;
  while (left < right) {
    if (isVowel(s[left])) {
      while (!isVowel(s[right])) {
        right--;
      }
      char temp = s[left];
      s[left] = s[right];
      s[right] = temp;
      right--;
    }
    left++;
  }

  return s;
}
