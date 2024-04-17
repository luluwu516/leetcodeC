#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool hasPathSum(struct TreeNode *root, int targetSum);
struct TreeNode *constructBinaryTree(int *nums, int size);

int main() {
  // declaration
  int size, targetSum;
  bool result;

  // input
  printf("Enter the size of the tree: ");
  scanf("%d", &size);
  int nums[size];

  printf("Enter numbers: \n");
  for (int i = 0; i < size; i++) {
    printf("> ");
    scanf("%d", &nums[i]);
  }

  printf("\nEnter the target Sum: ");
  scanf("%d", &targetSum);

  struct TreeNode *root = constructBinaryTree(nums, size);

  // processing
  result = hasPathSum(root, targetSum);

  // output
  printf("\n\nResult:\n");
  printf("The root-to-leaf path with the target sum is %s\n\n",
         (result ? "shown" : "not shown"));

  return 0;
}

struct TreeNode *constructBinaryTree(int *nums, int size) {
  if (nums == NULL || size <= 0) {
    return NULL;
  }

  struct TreeNode *nodes = malloc(sizeof(struct TreeNode) * size);

  for (int i = 0; i < size; i++) {
    if (nums[i] != -1) {
      nodes[i].val = nums[i];
    } else {
      nodes[i].val = -1;
    }
    nodes[i].left = NULL;
    nodes[i].right = NULL;
  }

  int leftIndex = 1, rightIndex = 2;
  for (int i = 0; i < size; i++) {
    if (nums[i] != -1) {
      if (leftIndex < size && nums[leftIndex] != -1) {
        nodes[i].left = &nodes[leftIndex];
      }
      if (rightIndex < size && nums[rightIndex] != -1) {
        nodes[i].right = &nodes[rightIndex];
      }

      leftIndex += 2;
      rightIndex += 2;
    }
  }
  return &nodes[0];
}

bool hasPathSum(struct TreeNode *root, int targetSum) {
  if (!root) {
    return NULL;
  }

  if (!root->left && !root->right) {
    return targetSum == root->val;
  }
  bool left = hasPathSum(root->left, targetSum - root->val);
  bool right = hasPathSum(root->right, targetSum - root->val);

  return left || right;
}