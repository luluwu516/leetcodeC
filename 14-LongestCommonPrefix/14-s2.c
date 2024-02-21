#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize);

int main() {
  // Declaration
  char *strs[] = {"flower", "flow", "flight"};
  int size = sizeof(strs) / sizeof(strs[0]);

  // Processing
  char *prefix = longestCommonPrefix(strs, size);

  // Output
  printf("The longest common prefix: %s\n", prefix);

  free(prefix);

  return 0;
}

char *longestCommonPrefix(char **strs, int strsSize) {
  if (strsSize == 0) {
    return "";
  }

  char *prefix = (char *)malloc(strlen(strs[0]) + 1);
  strcpy(prefix, strs[0]);

  for (int i = 1; i < strsSize; i++) {
    int count = 0;
    while (strs[i][count] && prefix[count] && prefix[count] == strs[i][count]) {
      count++;
    }
    prefix[count] = '\0';
    if (strlen(prefix) == 0) {
      break;
    }
  }

  return prefix;
}