#include "stdio.h"
#include "stdlib.h"

int MAX = 100;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int *preorderTraversal(struct TreeNode *root, int *returnSize);
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
  int *result = preorderTraversal(root, &returnSize);

  // output
  printf("\n\nResult:\n");
  for (int i = 0; i < returnSize; i++) {
    printf("%d ", result[i]);
  }
  puts("\n");

  free(result);

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

int *preorderTraversal(struct TreeNode *root, int *returnSize) {
  int *res = (int *)malloc(sizeof(int) * MAX);
  struct TreeNode *stack[MAX];
  struct TreeNode *curr = root;

  int index = 0, top = -1;
  while (curr || top != -1) {
    while (curr) {
      res[index++] = curr->val;
      top++;
      stack[top] = curr;
      curr = curr->left;
    }
    curr = stack[top--];
    curr = curr->right;
  }

  *returnSize = index;
  return res;
}
