#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool wordPattern(char* pattern, char* s);

int main() {
  // declaration
  int pattern_size, num;
  char pattern[300], words[3000];
  bool res;

  // input
  printf("\nEnter pattern: ");
  fgets(pattern, 300, stdin);
  int i = 0;
  while (pattern[i] != '\n') {
    i++;
  }
  pattern[i] = '\0';

  printf("Enter words (seperated by space): ");
  fgets(words, 3000, stdin);
  i = 0;
  while (pattern[i] != '\n') {
    i++;
  }
  pattern[i] = '\0';

  // processing
  res = wordPattern(pattern, words);

  // output
  printf("\nResult: \n");
  printf("The pattern and words are%s match\n\n", (res ? "" : " not"));

  return 0;
}

bool wordPattern(char* pattern, char* s) {
  int pattern_len = strlen(pattern);
  int words_len = strlen(s);

  if (pattern_len == 0 || words_len == 0) {
    return false;
  }

  char* hashMap[26];
  memset(hashMap, 0, sizeof(char*) * 26);

  char* word;
  char* token = strtok(s, " ");
  int i = 0;

  while (token != NULL) {
    if (i >= pattern_len) {
      return false;
    }

    word = token;

    int index = pattern[i] - 'a';
    if (hashMap[index] == NULL) {
      for (int j = 0; j < 26; j++) {
        if (hashMap[j] != NULL && strcmp(hashMap[j], word) == 0) {
          return false;
        }
      }
      hashMap[index] = word;
    } else {
      if (strcmp(hashMap[index], word) != 0) {
        return false;
      }
    }

    token = strtok(NULL, " ");
    i++;
  }

  return i == pattern_len;
}