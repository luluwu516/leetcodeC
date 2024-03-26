#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int MAX = 100;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool helper(struct TreeNode *p, struct TreeNode *q);
bool isSymmetric(struct TreeNode *root);
struct TreeNode *constructBinaryTree(int *nums, int size);

int main() {
  // declaration
  int size;
  bool isSym;

  // input
  printf("Enter the size of the first tree: ");
  scanf("%d", &size);
  int nums[size];

  printf("Enter numbers: \n");
  for (int i = 0; i < size; i++) {
    printf("> ");
    scanf("%d", &nums[i]);
  }

  struct TreeNode *root = constructBinaryTree(nums, size);

  // processing
  isSym = isSymmetric(root);

  // output
  printf("\n\nResult:\n");
  if (isSym) {
    printf("This is a symmetric tree.\n\n");
  } else {
    printf("This is not a symmetric tree.\n\n");
  }

  return 0;
}

bool isSymmetric(struct TreeNode *root) {
  return helper(root->left, root->right);
}

bool helper(struct TreeNode *p, struct TreeNode *q) {
  if (p == NULL && q == NULL) {
    return true;
  }
  if (p == NULL || q == NULL) {
    return false;
  }
  if (p->val != q->val) {
    return false;
  }

  return helper(p->left, q->right) && helper(p->right, q->left);
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