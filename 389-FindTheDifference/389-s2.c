#include <stdio.h>
#include <string.h>

// function prototype
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

char findTheDifference(char* s, char* t) {
  if (!s) {
    return *t;
  }
  int letters[26] = {0};
  int i;

  for (i = 0; s[i] != '\0'; ++i) {
    letters[s[i] - 'a']++;
    letters[t[i] - 'a']--;
  }
  letters[t[i] - 'a']--;

  for (i = 0; i < 26; i++) {
    if (letters[i] < 0) {
      return (char)(i + 97);
    }
  }
  return t[strlen(s)];
}