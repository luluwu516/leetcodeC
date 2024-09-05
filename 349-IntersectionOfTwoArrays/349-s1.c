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
  int* res = (int*)malloc(sizeof(int));
  int count = 0;
  for (int i = 0; i < nums1Size; i++) {
    for (int j = 0; j < nums2Size; j++) {
      if (nums1[i] == nums2[j]) {
        int firstFound = 0;
        for (int k = 0; k < count; k++) {
          if (res[k] == nums1[i]) {
            firstFound = 1;
            break;
          }
        }
        if (!firstFound) {
          res = realloc(res, sizeof(int) * (count + 1));
          res[count] = nums1[i];
          count++;
        }
        break;
      }
    }
  }
  *returnSize = count;
  return res;
}