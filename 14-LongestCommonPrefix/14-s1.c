#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize);

int main() {
  // declaration
  int size;
  char input[120];
  char* prefix;

  // input
  printf("Enter the size of the list: ");
  scanf("%d", &size);

  char* strs[size];
  char** strsPtr = strs;

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

// `malloc()` version
char* longestCommonPrefix(char** strs, int strsSize) {
  if (strsSize == 0) {
    return "";
  }

  for (int i = 0; i < strlen(strs[0]); i++) {
    for (int j = 1; j < strsSize; j++) {
      if (i >= strlen(strs[j]) || strs[0][i] != strs[j][i]) {
        char* prefix = malloc(i + 1);
        if (prefix != NULL) {
          strncpy(prefix, strs[0], i);
          prefix[i] = '\0';
        }
        return prefix;
      }
    }
  }

  return strs[0];
}

// `static` version
// char* longestCommonPrefix(char** strs, int strsSize) {
//   if (strsSize == 0) {
//     return "";
//   }

//   // Use `static`, so we don't need to use malloc()
//   static char prefix[120];
//   for (int i = 0; i < strlen(strs[0]); i++) {
//     for (int j = 1; j < strsSize; j++) {
//       if (i >= strlen(strs[j]) || strs[0][i] != strs[j][i]) {
//         strncpy(prefix, strs[0], i);
//         prefix[i] = '\0';
//         return prefix;
//       }
//     }
//   }

//   return strs[0];
// }

// Similar one, but it will change the strs[0]
// char* longestCommonPrefix(char** strs, int strsSize) {
//   if (strsSize == 0) {
//     return "";
//   }

//   for (int i = 0; i < strlen(strs[0]); i++) {
//     for (int j = 1; j < strsSize; j++) {
//       if (i >= strlen(strs[j]) || strs[0][i] != strs[j][i]) {
//         strs[0][i] = '\0';
//       }
//     }
//   }

//   return strs[0];
// }