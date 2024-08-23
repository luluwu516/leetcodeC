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
  int left = 0, right = sSize - 1;
  while (left < right) {
    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;
    left++;
    right--;
  }
}