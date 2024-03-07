#include <stdio.h>
#include <stdlib.h>

int searchInsert(int *nums, int numsSize, int target);

int main() {
  // declaration
  int size, target;
  int result;

  // input
  printf("Enter the size of the list: ");
  scanf("%d", &size);

  int nums[size];

  printf("Enter list numbers: ");
  for (int i = 0; i < size; i++) {
    printf("> ");
    scanf("%d", &nums[i]);
  }

  printf("Enter the target: ");
  scanf("%d", &target);

  result = searchInsert(nums, size, target);

  // output
  printf("The target \"%d\" should be inserted at index %d\n", target, result);

  return 0;
}

int searchInsert(int *nums, int numsSize, int target) {
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] >= target) {
      return i;
    }
  }
  return numsSize;
}