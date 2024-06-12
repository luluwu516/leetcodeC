#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10000

struct ListNode {
  int val;
  struct ListNode* next;
};

// function prototype
struct ListNode* reverseList(struct ListNode* head);
struct ListNode* constructLinkList(int* nums, int size);
void printLinkList(struct ListNode* head);
void freeLinkList(struct ListNode* head);

int main() {
  // declaration
  int num, i = 0;
  int nums[MAX_SIZE];
  struct ListNode *head, *res;

  // input
  printf("\nEnter numbers to build a Linked List, -1 to stop: \n");
  while (1) {
    printf("> ");
    scanf("%d", &num);
    if (num == -1) {
      break;
    }
    nums[i++] = num;
  }

  head = constructLinkList(nums, i);

  // processing and output
  printf("\nResult:\n");
  printf("Original: ");
  printLinkList(head);

  res = reverseList(head);
  printf("Revised : ");
  printLinkList(res);

  freeLinkList(res);

  return 0;
}

struct ListNode* constructLinkList(int* nums, int size) {
  if (size == 0) return NULL;

  struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
  struct ListNode* curr = head;
  curr->val = nums[0];

  for (int i = 1; i < size; ++i) {
    curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    curr = curr->next;
    curr->val = nums[i];
  }
  curr->next = NULL;  // Mark the end of the list

  return head;
}

void printLinkList(struct ListNode* head) {
  struct ListNode* curr = head;
  while (curr) {
    printf("%d ", curr->val);
    curr = curr->next;
  }
  printf("\n");
}

void freeLinkList(struct ListNode* head) {
  struct ListNode* curr = head;
  while (curr) {
    struct ListNode* temp = curr;
    curr = curr->next;
    free(temp);
  }
}

struct ListNode* reverseList(struct ListNode* head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  struct ListNode* rHead = NULL;
  struct ListNode *curr = head, *temp;

  while (curr) {
    temp = curr->next;
    curr->next = rHead;
    rHead = curr;
    curr = temp;
  }

  return rHead;
}