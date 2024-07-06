#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define SIZE 200000

bool isAnagram(char* s, char* t);

int main() {
  // declaration
  char *s, *t;
  bool res;

  // input
  printf("\nEnter a string: ");
  fgets(s, SIZE, stdin);
  printf("Enter another string: ");
  fgets(t, SIZE, stdin);

  // processing
  res = isAnagram(s, t);

  // output
  printf("\nResult:\n");
  printf("The strings are %s\n\n", (res ? "anagram" : "not anagram"));

  return 0;
}

bool isAnagram(char* s, char* t) {
  if (strlen(s) != strlen(t)) {
    return false;
  }
  int len = strlen(s);
  int letters[26] = {0};

  for (int i = 0; i < len; i++) {
    letters[s[i] - 'a']++;
    letters[t[i] - 'a']--;
  }
  for (int i = 0; i < 26; i++) {
    if (letters[i] != 0) {
      return false;
    }
  }
  return true;
}