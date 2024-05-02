#include <stdio.h>
#include <stdlib.h>

int compare(const void* num1, const void* num2);
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
  qsort(nums, numsSize, sizeof(int), compare);

  for (int i = 0; i < numsSize - 1; i += 2)
    if (nums[i] != nums[i + 1]) {
      return nums[i];
    }

  return nums[numsSize - 1];
}

int compare(const void* num1, const void* num2) {
  if (*(int*)num1 > *(int*)num2)
    return 1;
  else
    return -1;
}