#include <stdio.h>
#include <stdlib.h>

// function prototype
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size,
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
  res = intersect(nums1, nums1Size, nums2, nums2Size, &returnSize);

  // output
  printf("\nResult: \n");
  printf("The intersection of two integer arrays is: \n");
  for (int i = 0; i < returnSize; i++) {
    printf("%d", res[i]);
    if (i != returnSize - 1) {
      printf(", ");
    }
  }
  puts("\n");

  return 0;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size,
               int* returnSize) {
  size_t size = nums1Size > nums2Size ? nums1Size : nums2Size;
  int* res = (int*)malloc(sizeof(int) * size);
  int count = 0;
  for (int i = 0; i < nums1Size; i++) {
    for (int j = 0; j < nums2Size; j++) {
      if (nums1[i] == nums2[j] && nums2[j] != -1) {
        res[count++] = nums1[i];
        nums2[j] = -1;
        break;
      }
    }
  }
  *returnSize = count;

  return res;
}