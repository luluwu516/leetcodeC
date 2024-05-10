#include "stdio.h"
#include "stdlib.h"

int MAX = 100;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int *postorderTraversal(struct TreeNode *root, int *returnSize);
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
  int *result = postorderTraversal(root, &returnSize);

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

int *postorderTraversal(struct TreeNode *root, int *returnSize) {
  if (root == NULL) {
    *returnSize = 0;
    return NULL;
  }

  int *res = (int *)malloc(sizeof(int) * MAX);
  struct TreeNode **st =
      (struct TreeNode **)malloc(sizeof(struct TreeNode *) * MAX);
  struct TreeNode *curr = root;
  struct TreeNode *lastVisit = NULL;

  int i = 0, index = 0, top_i = -1;
  while (curr || top_i != -1) {
    if (curr) {
      st[++top_i] = curr;
      curr = curr->left;
    } else {
      struct TreeNode *top = st[top_i];
      if (top->right != NULL && lastVisit != top->right) {
        curr = top->right;
      } else {
        res[i++] = top->val;
        top_i--;
        lastVisit = top;
      }
    }
  }

  *returnSize = i;
  free(st);
  return res;
}
