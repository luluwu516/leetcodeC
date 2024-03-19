#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
  int val;
  struct ListNode* next;
} ListNode;

ListNode* deleteDuplicates(ListNode* head);

void printList(ListNode* head);

int main() {
  // declaration
  ListNode* head = NULL;
  int num;

  // input
  printf("\nEnter numbers, -1 to stop: ");
  scanf("%d", &num);

  while (num != -1) {
    ListNode* newPtr = malloc(sizeof(ListNode));
    if (newPtr != NULL) {
      newPtr->val = num;
      newPtr->next = NULL;
    } else {
      free(newPtr);
      return 1;
    }

    if (head == NULL) {
      head = newPtr;
    } else {
      ListNode* curr = head;
      while (curr->next != NULL) {
        curr = curr->next;
      }
      curr->next = newPtr;
    }
    printf("Enter numbers, -1 to stop: ");
    scanf("%d", &num);
  }

  printf("\nOriginal list: ");
  printList(head);

  // processing
  ListNode* result = deleteDuplicates(head);

  // output
  printf("\nResult: ");
  printList(result);

  return 0;
}

ListNode* deleteDuplicates(ListNode* head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  ListNode* prev = head;
  ListNode* curr = head->next;

  while (curr != NULL) {
    if (curr->val == prev->val) {
      curr = curr->next;
      prev->next = curr;
    } else {
      curr = curr->next;
      prev = prev->next;
    }
  }

  return head;
}

void printList(ListNode* head) {
  ListNode* curr = head;
  while (curr != NULL) {
    printf("%d -> ", curr->val);
    curr = curr->next;
  }
  printf("None\n\n");
}