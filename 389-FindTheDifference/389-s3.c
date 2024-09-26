#include <stdio.h>
#include <string.h>

// function prototype
int compare(const void* a, const void* b);
char findTheDifference(char* s, char* t);

int main() {
  // declaration
  char *s, *t;
  int size;
  char res;

  // input
  printf("\nEnter s: ");
  fgets(s, 1000, stdin);
  size = strlen(s);
  s[strcspn(s, "\n")] = '\0';

  printf("Enter t: ");
  fgets(t, size + 1, stdin);
  t[strcspn(t, "\n")] = '\0';

  // processing
  res = findTheDifference(s, t);

  // output
  printf("\n\nResult: \n");
  printf("'%c' is the letter that was added\n\n", res);

  return 0;
}

int compare(const void* a, const void* b) { return strcmp((char*)a, (char*)b); }

char findTheDifference(char* s, char* t) {
  if (!s) {
    return *t;
  }
  int sIndex = 0, tIndex = 0;
  int sumS = 0, sumT = 0;

  while (s[sIndex] != '\0' && t[tIndex] != '\0') {
    sumS += s[sIndex];
    sumT += t[tIndex];
    sIndex++;
    tIndex++;
  }
  sumT += t[tIndex];
  return (char)(sumT - sumS);
}