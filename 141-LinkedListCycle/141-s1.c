#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

// function prototype
struct ListNode *constructLinkedList(int *nums, int size, int pos);
bool hasCycle(struct ListNode *head);

int main() {
  // declaration
  int size, pos;
  bool res;

  // input
  printf("\nEnter the size of the Linked List: ");
  scanf("%d", &size);
  int nums[size];

  printf("Enter numbers: \n");
  for (int i = 0; i < size; i++) {
    printf("> ");
    scanf("%d", &nums[i]);
  }

  printf(
      "\nEnter the connected position or -1 to create a linked list without a "
      "cycle: ");
  scanf("%d", &pos);

  // processing
  struct ListNode *head = constructLinkedList(nums, size, pos);
  res = hasCycle(head);

  // output
  printf("\nResult:\n");
  printf("The linked list %s a cycle\n", (res ? "has" : "doesn't have"));

  return 0;
}

struct ListNode *constructLinkedList(int *nums, int size, int pos) {
  if (nums == NULL || size <= 0) {
    return NULL;
  }

  struct ListNode *nodes = malloc(sizeof(struct ListNode) * size);

  for (int i = 0; i < size; i++) {
    nodes[i].val = nums[i];
  }
  for (int i = 0; i < size - 1; i++) {
    nodes[i].next = &nodes[i + 1];
  }

  if (pos >= 0 && pos < size) {
    nodes[size - 1].next = &nodes[pos];
  }

  return &nodes[0];
}

bool hasCycle(struct ListNode *head) {
  struct ListNode *fast = head;
  struct ListNode *slow = head;

  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;

    if (fast == slow) {
      return true;
    }
  }

  return false;
}