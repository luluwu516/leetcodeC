#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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
  int size_m = strlen(magazine), size_r = strlen(ransomNote);
  if (size_r > size_m) {
    return false;
  }
  int count = 0;
  int magazineCounter[size_m];
  for (int i = 0; i < size_m; i++) {
    magazineCounter[i] = 0;
  }

  for (int i = 0; i < size_r; i++) {
    char c = ransomNote[i];
    for (int j = 0; j < size_m; j++) {
      char cInM = magazine[j];
      if (c == cInM && magazineCounter[j] == 0) {
        count++;
        magazineCounter[j] = 1;
        break;
      }
    }
  }

  return count == strlen(ransomNote);
}