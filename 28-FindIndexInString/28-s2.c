#include <stdbool.h>
#include <stdio.h>

int strStr(char* haystack, char* needle);

int main() {
  // declaration
  char haystack[20], needle[20];
  int index;

  // input
  printf("\nEnter the first string: ");
  scanf("%s", haystack);

  printf("Enter the second string: ");
  scanf("%s", needle);

  // processing
  index = strStr(haystack, needle);

  // output
  printf("\nResult\n");
  if (index != -1) {
    printf("The first \"%s\" occurs at index %d\n", needle, index);
  } else {
    printf("\"%s\" did not occur in \"%s\"\n\n", needle, haystack);
  }

  return 0;
}

int strStr(char* haystack, char* needle) {
  int i = 0;
  bool flag = false;
  while (haystack[i] != '\0') {
    if (haystack[i] == needle[0]) {
      flag = true;
      int j = 0;
      while (needle[j] != '\0') {
        if (needle[j] != haystack[i + j]) {
          flag = false;
          break;
        }
        j++;
      }
      if (flag) {
        return i;
      }
    }
    i++;
  }

  return -1;
}