#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 5000

// function prototype
bool isIsomorphic(char* s, char* t);

int main() {
  // declaration
  char s[MAX], t[MAX];
  bool res;

  // input
  printf("Enter a string      : ");
  scanf("%s", s);
  printf("Enter another string: ");
  scanf("%s", t);

  // processing
  res = isIsomorphic(s, t);

  // output
  printf("\nResult:\n");
  printf("Two strings are %s\n", (res ? "isomorphic" : "not isomorphic"));

  return 0;
}

bool isIsomorphic(char* s, char* t) {
  if (s == NULL || t == NULL) {
    return false;
  }

  int len = 0;
  while (s[len] != '\0') {
    len++;
  }

  char mapS[MAX] = {0};
  char mapT[MAX] = {0};

  for (int i = 0; i < len; i++) {
    if (mapS[s[i]] == 0 && mapT[t[i]] == 0) {
      mapS[s[i]] = t[i];
      mapT[t[i]] = s[i];
    } else if (mapS[s[i]] != t[i] || mapT[t[i]] != s[i]) {
      return false;
    }
  }
  return true;
}