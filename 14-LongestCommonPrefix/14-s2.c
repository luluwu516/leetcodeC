#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize);

int main() {
  // declaration
  int size;
  char input[120];
  char *prefix;

  // input
  printf("Enter the size of the list: ");
  scanf("%d", &size);

  char *strs[size];
  char **strsPtr = strs;

  printf("Enter a list of strings separated by new line: \n");
  for (int i = 0; i < size; i++) {
    printf("> ");
    scanf("%s", input);
    strs[i] = strdup(input);
  }

  // Processing
  prefix = longestCommonPrefix(strs, size);

  // Output
  printf("\nThe longest common prefix: %s\n", prefix);

  free(prefix);
  for (int i = 0; i < size; i++) {
    free(strs[i]);
  }

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