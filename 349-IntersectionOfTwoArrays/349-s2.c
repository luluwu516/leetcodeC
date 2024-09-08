#include <stdio.h>
#include <stdlib.h>

// function prototype
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size,
                  int* returnSize);

int main() {
  // declaration
  int nums1Size, nums2Size, returnSize;
  int *nums1, *nums2, *res;

  // input
  printf("Enter the size of array 1: ");
  scanf("%d", &nums1Size);
  nums1 = (int*)malloc(sizeof(int) * nums1Size);
  puts("Enter the numbers: ");
  for (int i = 0; i < nums1Size; i++) {
    printf("> ");
    scanf("%d", &nums1[i]);
  }

  printf("\nEnter the size of array 2: ");
  scanf("%d", &nums2Size);
  nums2 = (int*)malloc(sizeof(int) * nums2Size);
  puts("Enter the numbers: ");
  for (int i = 0; i < nums2Size; i++) {
    printf("> ");
    scanf("%d", &nums2[i]);
  }

  // processing
  res = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);

  // output
  printf("\nResult: \n");
  printf("The intersection of two integer arrays is: \n");
  for (int i = 0; i < returnSize; i++) {
    printf("%d ", res[i]);
  }
  puts("\n");

  return 0;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size,
                  int* returnSize) {
  int i, j = 0;
  int size = nums1Size < nums2Size ? nums1Size : nums2Size;
  int hash[1001] = {0};
  int* res = (int*)malloc(size * sizeof(int));

  for (i = 0; i < nums1Size; i++) hash[nums1[i]] = 1;

  for (i = 0; i < nums2Size; i++) {
    if (hash[nums2[i]] == 1) {
      res[j++] = nums2[i];
      hash[nums2[i]] = 2;
    }
  }

  *returnSize = j;

  return res;
}