#include <stdio.h>
#include <stdlib.h>
#define MIN(x, y) (x < y ? x : y)

int MAX = 100;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int minDepth(struct TreeNode *root);
int helper(struct TreeNode *root);
struct TreeNode *constructBinaryTree(int *nums, int size);

int main() {
  // declaration
  int size;
  int result;

  // input
  printf("Enter the size of the tree: ");
  scanf("%d", &size);
  int nums[size];

  printf("Enter numbers: \n");
  for (int i = 0; i < size; i++) {
    printf("> ");
    scanf("%d", &nums[i]);
  }

  struct TreeNode *root = constructBinaryTree(nums, size);

  // processing
  result = minDepth(root);

  // output
  printf("\n\nResult:\n");
  printf("The minimum depth of the tree is %d\n\n", result);

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

int minDepth(struct TreeNode *root) { return helper(root); }

int helper(struct TreeNode *root) {
  if (!root) {
    return 0;
  } else if (!root->left && !root->right) {
    return 1;
  } else if (!root->left) {
    return helper(root->right) + 1;
  } else if (!root->right) {
    return helper(root->left) + 1;
  } else {
    return MIN(helper(root->left), helper(root->right)) + 1;
  }
}