#include <stdio.h>

int climbStairs(int n);

int main() {
  // declaration
  int num, result;

  // input
  printf("\nEnter how many steps in a staircase: ");
  scanf("%d", &num);

  result = climbStairs(num);

  // output
  printf("\n\nResult:\n");
  printf("There are %d ways to climb to the top.\n\n", result);

  return 0;
}

int climbStairs(int n) {
  if (n < 2) {
    return 1;
  }

  int prev = 1, curr = 1;

  for (int i = 2; i < n + 1; i++) {
    int temp = curr;
    curr += prev;
    prev = temp;
  }

  return curr;
}
