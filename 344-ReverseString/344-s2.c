#include <stdio.h>
#include <stdlib.h>

// function prototype
void reverseString(char* s, int sSize);

int main() {
  // declaration
  int size;
  char c;

  // input
  printf("\nEnter the size of the array: ");
  scanf("%d", &size);
  getchar();

  char* letters = (char*)malloc(sizeof(char) * size);
  printf("Enter letter(s): ");
  int index = 0;
  while (scanf("%c", &c)) {
    letters[index] = c;
    index++;
    if (index == size) {
      break;
    }
  }

  printf("\nInput: ");
  for (int i = 0; i < size; i++) {
    printf("%c ", letters[i]);
  }

  // processing
  reverseString(letters, size);

  // output
  printf("\nResult: ");
  for (int i = 0; i < size; i++) {
    printf("%c ", letters[i]);
  }
  puts("\n");

  return 0;
}

void reverseString(char* s, int sSize) {
  for (int i = 0; i < (sSize / 2); i++) {
    char temp = s[i];
    s[i] = s[sSize - 1 - i];
    s[sSize - 1 - i] = temp;
  }
}