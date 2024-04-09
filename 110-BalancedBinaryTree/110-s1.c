#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool isBalanced(struct TreeNode *root);
int maxDepth(struct TreeNode *root);
int max(int a, int b);
struct TreeNode *constructBinaryTree(int *nums, int size);

int main() {
  // declaration
  int size;
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

  struct TreeNode *root = constructBinaryTree(nums, size);

  // processing
  result = isBalanced(root);

  // output
  printf("\n\nResult:\n");
  printf("The tree is %s\n\n", (result ? "balanced" : "not balanced"));

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

bool isBalanced(struct TreeNode *root) {
  if (root == NULL) {
    return true;
  }
  return maxDepth(root) != -1;
}

int maxDepth(struct TreeNode *root) {
  if (root == NULL) {
    return 0;
  }
  int left = maxDepth(root->left);
  int right = maxDepth(root->right);

  if (abs(left - right) > 1) {
    return -1;
  }
  if (left == -1 || right == -1) {
    return -1;
  }

  return max(left, right) + 1;
}

int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}