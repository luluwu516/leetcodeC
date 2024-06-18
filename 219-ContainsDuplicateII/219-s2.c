#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "uthash.h"

struct Hash {
  int key;
  int val;
  UT_hash_handle hh;
};

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
  struct Hash* table = NULL;
  struct Hash* entries = malloc(sizeof(struct Hash) * numsSize);
  struct Hash* pos = entries;
  bool ret = false;
  for (int i = 0; i < numsSize && !ret; ++i) {
    struct Hash* entry;
    HASH_FIND_INT(table, &nums[i], entry);
    if (!entry) {
      entry = pos++;
      entry->key = nums[i];
      entry->val = i;
      HASH_ADD_INT(table, key, entry);
    } else {
      if (entry->val + k >= i) {
        ret = true;
      }
      entry->val = i;
    }
  }

  HASH_CLEAR(hh, table);
  free(entries);

  return ret;
}