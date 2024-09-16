#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int pick;

// function prototype
int guessNumber(int n);
int guess(int num);

int main() {
  // declaration
  int num, res;
  printf("\nEnter the pick: ");
  scanf("%d", &pick);

  // input
  printf("Enter a number: ");
  scanf("%d", &num);

  // processing
  res = guessNumber(num);

  // output
  printf("\nResult: \n");
  printf("The pick number is %d\n\n", res);

  return 0;
}

int guess(int num) {
  if (num == pick) {
    return 0;
  } else if (num > pick) {
    return -1;
  } else {
    return 1;
  }
}

int guessNumber(int n) {
  int low = 0, high = n;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int res = guess(mid);
    if (res == 0) {
      return mid;
    } else if (res > 0) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}