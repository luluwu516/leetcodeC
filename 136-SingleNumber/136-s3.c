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
  int visited[numsSize];
  for (int i = 0; i < numsSize; i++) {
    visited[i] = 0;
  }

  for (int i = 0; i < numsSize; i++) {
    int hasDuplicate = 0;
    if (visited[i] == 0) {
      for (int j = i + 1; j < numsSize; j++) {
        if (nums[i] == nums[j]) {
          visited[i] = visited[j] = 1;
          hasDuplicate++;
        }
      }
      if (!hasDuplicate) {
        return nums[i];
      }
    }
  }

  return nums[numsSize - 1];
}