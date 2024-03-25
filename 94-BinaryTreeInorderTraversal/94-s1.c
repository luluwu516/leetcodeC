#include "stdio.h"
#include "stdlib.h"

int MAX = 100;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int *inorderTraversal(struct TreeNode *root, int *returnSize);
void helper(struct TreeNode *root, int *res, int *returnSize, int *index);
struct TreeNode *constructBinaryTree(int *nums, int size);

int main() {
  // declaration
  int size, returnSize;

  // input
  printf("Enter the size: ");
  scanf("%d", &size);
  int nums[size];

  printf("Enter numbers: \n");
  for (int i = 0; i < size; i++) {
    printf("> ");
    scanf("%d", &nums[i]);
  }

  struct TreeNode *root = constructBinaryTree(nums, size);

  // processing
  int *result = inorderTraversal(root, &returnSize);

  // output
  printf("\n\nResult:\n");
  for (int i = 0; i < returnSize; i++) {
    printf("%d ", result[i]);
  }
  puts("\n");

  free(result);

  return 0;
}

int *inorderTraversal(struct TreeNode *root, int *returnSize) {
  int *res = malloc(sizeof(int) * MAX);
  int index = 0;
  helper(root, res, returnSize, &index);
  *returnSize = index;
  return res;
}

void helper(struct TreeNode *root, int *res, int *returnSize, int *index) {
  if (root != NULL) {
    helper(root->left, res, returnSize, index);
    res[*index] = root->val;
    (*index)++;
    helper(root->right, res, returnSize, index);
  }
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