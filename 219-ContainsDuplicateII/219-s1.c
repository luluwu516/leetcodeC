#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Time Limit Exceeded
bool containsNearbyDuplicate(int* nums, int numsSize, int k);

int main() {
  // declaration
  int size, k;
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

  printf("\nEnter an integer k: ");
  scanf("%d", &k);

  // processing
  res = containsNearbyDuplicate(nums, size, k);

  // output
  printf("\n\nResult:\n");
  printf("The array %s duplicate\n\n", (res ? "contains" : "doesn't contain"));

  return 0;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
  int t;
  for (int i = 0; i < numsSize; i++) {
    t = 1;
    while (i + t < numsSize && k >= t) {
      if (nums[i] == nums[i + t]) {
        return true;
      }
      t++;
    }
  }
  return false;
}