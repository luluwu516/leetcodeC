#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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
  int* hashtable = (int*)malloc(sizeof(int) * numsSize);
  memset(hashtable, 0, sizeof(int) * numsSize);
  if (hashtable == NULL) {
    return false;
  }

  for (int i = 0; i < numsSize; i++) {
    int hash = abs(nums[i]) % numsSize;

    if (hashtable[hash] != 0 && nums[hashtable[hash] - 1] == nums[i]) {
      if (i - (hashtable[hash] - 1) <= k) {
        free(hashtable);
        return true;
      }
    }

    hashtable[hash] = i + 1;
  }
  free(hashtable);
  return false;
}