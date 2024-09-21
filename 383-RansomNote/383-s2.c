#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool canConstruct(char* ransomNote, char* magazine);

int main() {
  // declaration
  char *ransomNote, *magazine;
  bool res;

  // input
  printf("\nEnter ransom noter: ");
  scanf("%s", ransomNote);
  printf("Enter magazine: ");
  scanf("%s", magazine);

  // processing
  res = canConstruct(ransomNote, magazine);

  // output
  printf("\n\nResult: \n");
  printf("Each letter in magazine can%s only be used once in ransom note\n\n",
         (res ? "" : " not"));

  return 0;
}

bool canConstruct(char* ransomNote, char* magazine) {
  int letters[26] = {0};
  int size_m = strlen(magazine), size_r = strlen(ransomNote);
  for (int i = 0; i < size_m; i++) {
    letters[magazine[i] - 'a']++;
  }
  for (int i = 0; i < size_r; i++) {
    letters[ransomNote[i] - 'a']--;
    if (letters[ransomNote[i] - 'a'] < 0) {
      return false;
    }
  }

  return true;
}