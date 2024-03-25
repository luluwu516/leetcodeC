#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int MAX = 100;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool depth_first_search(struct TreeNode *p, struct TreeNode *q);
bool isSameTree(struct TreeNode *p, struct TreeNode *q);
struct TreeNode *constructBinaryTree(int *nums, int size);

int main() {
  // declaration
  int size1, size2;
  bool isSame;

  // input
  printf("Enter the size of the first tree: ");
  scanf("%d", &size1);
  int nums1[size1];

  printf("Enter numbers: \n");
  for (int i = 0; i < size1; i++) {
    printf("> ");
    scanf("%d", &nums1[i]);
  }

  printf("\nEnter the size of the second tree: ");
  scanf("%d", &size2);

  if (size1 != size2) {
    isSame = false;
  } else {
    int nums2[size2];

    printf("Enter numbers: \n");
    for (int i = 0; i < size2; i++) {
      printf("> ");
      scanf("%d", &nums2[i]);
    }

    struct TreeNode *root1 = constructBinaryTree(nums1, size1);
    struct TreeNode *root2 = constructBinaryTree(nums2, size2);

    // processing
    isSame = isSameTree(root1, root2);
  }

  // output
  printf("\n\nResult:\n");
  if (isSame) {
    printf("They are the same.\n\n");
  } else {
    printf("They are not the same.\n\n");
  }

  return 0;
}

bool depth_first_search(struct TreeNode *p, struct TreeNode *q) {
  if (p == NULL && q == NULL) {
    return true;
  }
  if (p == NULL || q == NULL) {
    return false;
  }
  if (p->val != q->val) {
    return false;
  }
  bool left = depth_first_search(p->left, q->left);
  bool right = depth_first_search(p->right, q->right);
  return left && right;
}

bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
  return depth_first_search(p, q);
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