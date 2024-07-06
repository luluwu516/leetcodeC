#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define SIZE 200000

int cmpstr(const void* a, const void* b);
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

int cmpstr(const void* a, const void* b) {
  return strcmp((const char*)a, (const char*)b);
}

bool isAnagram(char* s, char* t) {
  if (strlen(s) != strlen(t)) {
    return false;
  }
  int len = strlen(s);

  qsort(s, len, sizeof(char), cmpstr);
  qsort(t, len, sizeof(char), cmpstr);

  for (int i = 0; i < len; i++) {
    if (s[i] != t[i]) {
      return false;
    }
  }
  return true;
}