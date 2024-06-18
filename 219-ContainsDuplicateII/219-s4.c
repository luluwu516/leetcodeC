#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct data {
  int val;
  int idx;
};

int cmp(const void* a, const void* b);
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

int cmp(const void* a, const void* b) {
  return ((struct data*)a)->val - ((struct data*)b)->val;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
  struct data numsData[numsSize];
  for (int i = 0; i < numsSize; i++) {
    numsData[i].val = nums[i];
    numsData[i].idx = i;
  }

  qsort(numsData, numsSize, sizeof(struct data), cmp);

  for (int i = 1; i < numsSize; i++) {
    if (numsData[i].val == numsData[i - 1].val) {
      if (numsData[i].idx - numsData[i - 1].idx <= k) {
        return true;
      }
    }
  }

  return false;
}