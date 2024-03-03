#include <stdio.h>

int removeElement(int* nums, int numsSize, int val);

int main() {
  // declaration
  int size, val, dupCount;

  // input
  printf("Enter the size of the list: ");
  scanf("%d", &size);

  int nums[size];

  printf("\nEnter list numbers: \n");
  for (int i = 0; i < size; i++) {
    printf("> ");
    scanf("%d", &nums[i]);
  }

  printf("\nEnter the element to remove: ");
  scanf("%d", &val);

  // processing
  dupCount = removeElement(nums, size, val);

  // output
  printf("\n\nResult:\n");
  printf("%d duplicates and nums = [", dupCount);
  for (int i = 0; i < dupCount; i++) {
    printf("%d, ", nums[i]);
  }
  printf("]\n");

  return 0;
}

int removeElement(int* nums, int numsSize, int val) {
  //   if (numsSize == 0) {
  //     return 0;
  //   }

  int count = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != val) {
      nums[count] = nums[i];
      count++;
    }
  }

  return count;
}
