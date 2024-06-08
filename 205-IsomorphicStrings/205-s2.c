#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

  char mapS[128] = {0};
  char mapT[128] = {0};

  for (int i = 0; i < len; i++) {
    if (mapS[s[i]] != mapT[t[i]]) {
      return false;
    }
    mapS[s[i]] = i + 1;
    mapT[t[i]] = i + 1;
  }

  return true;
}