#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize);

int main() {
  // declaration
  int size, res;

  // input
  printf("Enter the size of the prices: ");
  scanf("%d", &size);

  int nums[size];
  printf("Enter the the price: \n");
  for (int i = 0; i < size; i++) {
    printf("> ");
    scanf("%d", &nums[i]);
  }

  // processing
  res = singleNumber(nums, size);

  // output
  printf("\n\nResult:\n");
  printf("Number %d only appears one time\n", res);

  return 0;
}

int singleNumber(int* nums, int numsSize) {
  int xor = 0;
  for (int i = 0; i < numsSize; i++) {
    xor ^= nums[i];
  }
  return xor;
}