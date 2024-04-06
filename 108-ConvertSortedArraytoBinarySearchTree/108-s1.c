#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *helper(int *nums, int left, int right);
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

struct TreeNode *helper(int *nums, int left, int right) {
  if (left > right) {
    return NULL;
  }
  int mid = left + (right - left) / 2;
  struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  if (!root) {
    return NULL;
  }
  root->val = nums[mid];
  root->left = helper(nums, left, mid - 1);
  root->right = helper(nums, mid + 1, right);
  return root;
}

struct TreeNode *sortedArrayToBST(int *nums, int numsSize) {
  if (numsSize <= 0) {
    return NULL;
  }
  return helper(nums, 0, numsSize - 1);
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