#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *sortedArrayToBST(int *nums, int numsSize);
void printBT(const char *prefix, const struct TreeNode *node, bool isLeft);

int main() {
  // declaration
  int size;
  struct TreeNode *result;

  // input
  printf("Enter the size of the tree: ");
  scanf("%d", &size);
  int nums[size];

  printf("Enter numbers: \n");
  for (int i = 0; i < size; i++) {
    printf("> ");
    scanf("%d", &nums[i]);
  }

  // processing
  result = sortedArrayToBST(nums, size);

  // output
  printf("\n\nResult:\n");
  printBT("", result, false);

  return 0;
}

struct TreeNode *sortedArrayToBST(int *nums, int numsSize) {
  if (numsSize <= 0) {
    return NULL;
  }
  int left = 0, right = numsSize - 1;
  int mid = left + (right - left) / 2;
  struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  if (!root) {
    return NULL;
  }
  root->val = nums[mid];
  root->left = sortedArrayToBST(nums, mid);
  root->right = sortedArrayToBST(nums + mid + 1, numsSize - mid - 1);
  return root;
}

void printBT(const char *prefix, const struct TreeNode *node, bool isLeft) {
  if (node != NULL) {
    printf("%s", prefix);
    printf("%s", isLeft ? "|-- " : "L-- ");
    printf("%d\n", node->val);
    char newPrefix[255];
    snprintf(newPrefix, sizeof(newPrefix), "%s%s", prefix,
             isLeft ? "|   " : "    ");
    printBT(newPrefix, node->right, true);
    printBT(newPrefix, node->left, false);
  }
}