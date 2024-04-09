#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) (x > y ? x : y)

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool isBalanced(struct TreeNode *root);
int check(struct TreeNode *root, bool *res);
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
  bool res = true;
  check(root, &res);
  return res;
}

int check(struct TreeNode *root, bool *res) {
  if (root == NULL) {
    return 0;
  }
  int left = check(root->left, res);
  int right = check(root->right, res);

  if (abs(left - right) > 1) {
    *res = false;
  }

  return MAX(left, right) + 1;
}