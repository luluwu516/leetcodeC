#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool containsDuplicate(int* nums, int numsSize);

int main() {
  // declaration
  int num, size;
  bool res;

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
  res = containsDuplicate(nums, size);

  // output
  printf("\n\nResult:\n");
  printf("The array %s duplicate\n\n", (res ? "contains" : "doesn't contain"));

  return 0;
}

bool containsDuplicate(int* nums, int numsSize) {
  int t;
  for (int i = 0; i < numsSize - 1; i++) {
    for (int j = i; j >= 0 && nums[j] >= nums[j + 1]; j--) {
      if (nums[j] == nums[j + 1]) {
        return true;
      }
      t = nums[j];
      nums[j] = nums[j + 1];
      nums[j + 1] = t;
    }
  }
  return false;
}