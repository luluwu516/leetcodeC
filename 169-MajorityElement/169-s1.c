#include "stdio.h"
#include "stdlib.h"

int majorityElement(int* nums, int numsSize);

int main() {
  // declaration
  int num, size;
  int res;

  // input
  printf("\nEnter the size of the list: ");
  scanf("%d", &size);
  int nums[size];

  printf("\nEnter the numbers:\n");
  for (int i = 0; i < size; i++) {
    printf("> ");
    scanf("%d", &nums[i]);
  }

  // processing
  res = majorityElement(nums, size);

  // output
  printf("\n\nResult:\n");
  printf("The majority element is '%d'\n\n", res);

  return 0;
}

int majorityElement(int* nums, int numsSize) {
  int majority = nums[0];
  int count = 0;
  for (int i = 0; i < numsSize; i++) {
    if (count == 0) {
      majority = nums[i];
      count++;
    } else if (majority == nums[i]) {
      count++;
    } else {
      count--;
    }
  }

  return majority;
}