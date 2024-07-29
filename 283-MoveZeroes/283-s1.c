#include <stdio.h>
#include <stdlib.h>

void moveZeroes(int* nums, int numsSize);

int main() {
  // declaration
  int size, num;
  int* nums;

  // input
  printf("\nEnter the size of array: ");
  scanf("%d", &size);
  nums = (int*)malloc(size * sizeof(int));
  printf("Enter numbers (seperated by space): ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &num);
    nums[i] = num;
  }

  // processing
  moveZeroes(nums, size);

  // output
  printf("\nResult: \n");
  for (int i = 0; i < size; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n\n");

  return 0;
}

void moveZeroes(int* nums, int numsSize) {
  int left = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != 0) {
      int t = nums[i];
      nums[i] = nums[left];
      nums[left] = t;
      left++;
    }
  }
}