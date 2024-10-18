#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// function prototype
bool isSubsequence(char* s, char* t);

int main() {
  // declaration
  char *str1, *str2;
  bool res;

  // input
  printf("\nEnter string 1: ");
  scanf("%s", str1);
  printf("Enter string 2: ");
  scanf("%s", str2);

  // processing
  res = isSubsequence(str1, str2);

  // output
  printf("\nResult: \n");
  printf(
      "'s' is%s a new string that is formed from 't' by deleting some (can be "
      "none) of the characters\n\n",
      res ? "" : " not");

  return 0;
}

bool isSubsequence(char* s, char* t) {
  int lenS = strlen(s);
  int lenT = strlen(t);
  int index = 0, i = 0;

  while (index < lenS && i < lenT) {
    if (s[index] == t[i]) {
      index++;
    }
    i++;
  }
  return index == lenS;
}