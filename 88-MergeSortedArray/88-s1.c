#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);
void printList(int* nums, int size);

int main() {
  // declaration
  int num, nums1_size, nums2_size;

  // input
  printf("\nnums1:\n");
  printf("Enter the size of nums1: ");
  scanf("%d", &nums1_size);

  int nums1[nums1_size];

  printf("Enter numbers: \n");
  for (int i = 0; i < nums1_size; i++) {
    printf("> ");
    scanf("%d", &nums1[i]);
  }

  printf("\nnums2:\n");
  printf("Enter the size of nums2: ");
  scanf("%d", &nums2_size);

  int nums2[nums2_size];

  printf("Enter numbers: ");
  for (int i = 0; i < nums2_size; i++) {
    printf("> ");
    scanf("%d", &nums2[i]);
  }

  int nums[nums1_size + nums2_size];
  int index;
  for (index = 0; index < nums1_size; index++) {
    nums[index] = nums1[index];
  }
  for (; index < nums1_size + nums2_size; index++) {
    nums[index] = 0;
  }

  printf("\nOriginal list: \n");
  printf("nums1: ");
  printList(nums, nums1_size + nums2_size);
  printf("nums2: ");
  printList(nums2, nums2_size);

  // processing
  merge(nums, nums1_size + nums2_size, nums1_size, nums2, nums2_size,
        nums2_size);

  // output
  printf("\n\nResult:\n");
  printList(nums, nums1_size + nums2_size);
  puts("");

  return 0;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
  int i = 0, j = 0;
  int index = 0;
  int nums[m + n];

  while (i < m && j < n) {
    if (nums1[i] < nums2[j]) {
      nums[index] = nums1[i];
      i++;
    } else {
      nums[index] = nums2[j];
      j++;
    }
    index++;
  }
  while (i < m) {
    nums[index] = nums1[i];
    i++;
    index++;
  }
  while (j < n) {
    nums[index] = nums2[j];
    j++;
    index++;
  }

  for (int k = 0; k < m + n; k++) {
    nums1[k] = nums[k];
  }
}

void printList(int* nums, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", nums[i]);
  }
  puts("");
}