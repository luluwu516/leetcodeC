#include <stdio.h>

int missingNumber(int* nums, int numsSize);

int main() {
  // declaration
  int size, res;

  // input
  printf("\nEnter the size of the array: ");
  scanf("%d", &size);
  int nums[size];
  for (int i = 0; i < size; i++) {
    printf("Enter the number %d: ", i + 1);
    scanf("%d", &nums[i]);
  }

  // processing
  res = missingNumber(nums, size);

  // output
  printf("Result: \n\n");
  printf("The missing number is %d\n\n", res);

  return 0;
}

int missingNumber(int* nums, int numsSize) {
  int res = 0;
  for (int i = 1; i < numsSize + 1; i++) {
    res ^= i;
  }
  for (int i = 0; i < numsSize; i++) {
    res ^= nums[i];
  }
  return res;
}