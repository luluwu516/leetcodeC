#include <stdbool.h>
#include <stdio.h>
#include <string.h>

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
  int haystack_len = strlen(haystack);
  int needle_len = strlen(needle);

  if (haystack_len < needle_len) {
    return -1;
  }

  for (int i = 0; i < haystack_len - needle_len + 1; i++) {
    bool flag = false;
    if (haystack[i] == needle[0]) {
      flag = true;
      for (int j = 0; j < needle_len; j++) {
        if (haystack[i + j] != needle[j]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        return i;
      }
    }
  }

  return -1;
}