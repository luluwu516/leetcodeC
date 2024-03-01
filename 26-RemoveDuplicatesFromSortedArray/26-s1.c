#include <stdio.h>

int removeDuplicates(int* nums, int numsSize);

int main() {
  // declaration
  int size, uniqueNumCount;

  // input
  printf("Enter the size of the list: ");
  scanf("%d", &size);

  int nums[size];

  printf("Enter list numbers: \n");
  for (int i = 0; i < size; i++) {
    printf("> ");
    scanf("%d", &nums[i]);
  }

  // processing
  uniqueNumCount = removeDuplicates(nums, size);

  // output
  printf("\n\nResult:\n");
  printf("%d unique number(s). nums = [", uniqueNumCount);
  for (int i = 0; i < uniqueNumCount; i++) {
    printf("%d, ", nums[i]);
  }
  printf("]\n");

  return 0;
}

int removeDuplicates(int* nums, int numsSize) {
  if (numsSize <= 1) {
    return numsSize;
  }

  int unique = 1;
  for (int i = 1; i < numsSize; i++) {
    if (nums[i - 1] != nums[i]) {
      nums[unique] = nums[i];
      unique++;
    }
  }

  return unique;
}