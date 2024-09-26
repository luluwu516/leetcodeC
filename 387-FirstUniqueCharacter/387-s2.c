#include <stdio.h>

int firstUniqChar(char* s);

int main() {
  // declaration
  char* str;
  int res;

  // input
  printf("\nEnter ransom noter: ");
  scanf("%s", str);

  // processing
  res = firstUniqChar(str);

  // output
  printf("\n\nResult: \n");
  if (res != -1) {
    printf(
        "The character %c at index %d is the first character that does not "
        "occur at any other index.\n\n",
        str[res], res);
  } else {
    printf("The non-repeating character does not exist.\n\n");
  }

  return 0;
}

int firstUniqChar(char* s) {
  for (int i = 0; s[i] != '\0'; i++) {
    int foundSecond = 0;
    for (int j = 0; s[j] != '\0'; j++) {
      if (i == j) {
        continue;
      }
      if (s[i] == s[j]) {
        foundSecond = 1;
        break;
      }
    }
    if (!foundSecond) {
      return i;
    }
  }
  return -1;
}
