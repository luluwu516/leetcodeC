#include "stdio.h"
#include "stdlib.h"

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
  if (list1 == NULL && list2 == NULL) return NULL;
  if (list1 == NULL) return list2;
  if (list2 == NULL) return list1;

  struct ListNode head;
  struct ListNode* tailPtr = &head;

  while (list1 != NULL && list2 != NULL) {
    if (list1->val < list2->val) {
      tailPtr->next = list1;
      list1 = list1->next;
    } else {
      tailPtr->next = list2;
      list2 = list2->next;
    }
    tailPtr = tailPtr->next;
  }

  if (list1 != NULL) {
    tailPtr->next = list1;
  } else {
    tailPtr->next = list2;
  }

  return head.next;
}

void printList(struct ListNode* head) {
  while (head != NULL) {
    printf("%d ", head->val);
    head = head->next;
  }
}

struct ListNode* getInput() {
  struct ListNode* head = malloc(sizeof(struct ListNode));
  struct ListNode* temp = head;

  int input;

  printf("Enter the elements of list, -1 to stop: ");
  scanf("%d", &input);
  while (input != -1) {
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->val = input;
    newNode->next = NULL;
    if (head == NULL) {
      head = newNode;
      temp = head;
    } else {
      temp->next = newNode;
      temp = temp->next;
    }

    printf("Enter the elements of list, -1 to stop: ");
    scanf("%d", &input);
  }

  return head->next;
}

int main() {
  // declaration
  struct ListNode *list1Head, *list2Head, *mergedList;

  // Input
  printf("\nList 1\n");
  list1Head = getInput();
  printf("\nList 2\n");
  list2Head = getInput();

  printf("\nList 1: [ ");
  printList(list1Head);
  printf("]\n");
  printf("List 2: [ ");
  printList(list2Head);
  printf("]\n");

  // Processing
  printf("\nMerging...\n");
  mergedList = mergeTwoLists(list1Head, list2Head);

  // Output
  printf("\nResult:\n");
  printf("Merged List: [ ");
  printList(mergedList);
  printf("]\n");

  return 0;
}