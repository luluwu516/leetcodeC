#include <stdbool.h>
#include <stdio.h>

bool canWinNim(int n);

int main() {
  // declaration
  int num;
  bool res;

  // input
  printf("\nEnter the number of stones in the heap: ");
  scanf("%d", &num);

  // processing
  res = canWinNim(num);

  // output
  printf("\nResult: \n");
  printf("You can%s win the game.\n\n", (res ? "" : " not"));

  return 0;
}

bool canWinNim(int n) { return n % 4 != 0; }