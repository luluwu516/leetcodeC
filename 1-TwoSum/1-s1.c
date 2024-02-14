#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *, int, int, int *);

int main() {
  // declaration
  int size, target;
  int *result;
  int returnSize = 0;

  // input
  printf("Enter the size of the list: ");
  scanf("%d", &size);

  int nums[size];

  printf("Enter list numbers: ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &nums[i]);
  }

  printf("Enter the target: ");
  scanf("%d", &target);

  // printf("\nsize: %d\n", size);
  // printf("target: %d\n", target);
  // printf("nums: ");
  // for (int i = 0; i < size; i++) {
  //   printf("%d ", nums[i]);
  // }
  // puts("");

  // processing
  result = twoSum(nums, size, target, &returnSize);

  // output
  if (result == NULL) {
    printf("No two sum solution\n");
  } else {
    printf("\nResult: %d, %d\n", result[0], result[1]);
  }

  free(result);

  return 0;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  *returnSize = 2;
  int *ansPtr = malloc(2 * sizeof(int));
  if (ansPtr == NULL) {
    printf("Error!\n");
    return NULL;
  }
  for (int i = 0; i < numsSize - 1; i++) {
    for (int j = i + 1; j < numsSize; j++) {
      if (nums[i] + nums[j] == target) {
        ansPtr[0] = i;
        ansPtr[1] = j;
        return ansPtr;
      }
    }
  }
  return NULL;
}