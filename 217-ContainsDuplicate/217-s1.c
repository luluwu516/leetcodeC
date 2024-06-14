#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);
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

int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

bool containsDuplicate(int* nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), compare);
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] == nums[i - 1]) {
      return true;
    }
  }
  return false;
}