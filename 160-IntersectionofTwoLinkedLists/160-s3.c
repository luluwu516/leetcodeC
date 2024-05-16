#include "stdio.h"
#include "stdlib.h"

int MAX = 100;

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* getIntersectionNode(struct ListNode* headA,
                                     struct ListNode* headB);
struct ListNode* constructLinkedList(int* nums, int size);
void freeLinkedList(struct ListNode* head);
void constructIntersectedLinkedList(struct ListNode* headA,
                                    struct ListNode* headB, int intersectVal,
                                    int skipA, int skipB);

int main() {
  // declaration
  int sizeA, sizeB, returnSize;
  int intersectVal, skipA, skipB;
  struct ListNode *headA, *headB, *res;

  // input
  printf("Enter the sizeA: ");
  scanf("%d", &sizeA);
  int* numsA = (int*)malloc(sizeA * sizeof(int));

  printf("Enter numbers: \n");
  for (int i = 0; i < sizeA; i++) {
    printf("> ");
    scanf("%d", &numsA[i]);
  }

  printf("\nEnter the sizeB: ");
  scanf("%d", &sizeB);
  int* numsB = (int*)malloc(sizeB * sizeof(int));

  printf("Enter numbers: \n");
  for (int i = 0; i < sizeB; i++) {
    printf("> ");
    scanf("%d", &numsB[i]);
  }

  headA = constructLinkedList(numsA, sizeA);
  headB = constructLinkedList(numsB, sizeB);

  printf("\nEnter the intersect value: ");
  scanf("%d", &intersectVal);

  printf("\nEnter the skipA value: ");
  scanf("%d", &skipA);
  printf("Enter the skipB value: ");
  scanf("%d", &skipB);

  constructIntersectedLinkedList(headA, headB, intersectVal, skipA, skipB);

  // processing
  res = getIntersectionNode(headA, headB);

  // output
  printf("\n\nResult:\n");
  if (res) {
    printf("Intersected at '%d'\n", res->val);
  } else {
    printf("No intersection\n");
  }

  free(numsA);
  free(numsB);
  freeLinkedList(headA);
  freeLinkedList(headB);

  return 0;
}

struct ListNode* constructLinkedList(int* nums, int size) {
  if (nums == NULL || size <= 0) {
    return NULL;
  }
  struct ListNode* head = malloc(sizeof(struct ListNode));
  struct ListNode* curr = head;

  //   for (int i = 0; i < (size - 1); i++) {
  //     curr[i].val = nums[i];
  //     curr[i].next = &curr[i + 1];
  //   }

  for (int i = 0; i < size; i++) {
    curr->val = nums[i];
    if (i == size - 1) {
      curr->next = NULL;
    } else {
      curr->next = malloc(sizeof(struct ListNode));
      curr = curr->next;
    }
  }

  return head;
}

void constructIntersectedLinkedList(struct ListNode* headA,
                                    struct ListNode* headB, int intersectVal,
                                    int skipA, int skipB) {
  struct ListNode* currA = headA;
  struct ListNode* currB = headB;

  //   if (intersectVal) {
  //     for (int i = 0; i < skipA; i++) {
  //       currA = currA->next;
  //     }
  //     for (int i = 0; i < skipB; i++) {
  //       currB = currB->next;
  //     }
  //     currB->next = currA->next;
  //   }

  for (int i = 0; i < skipA; i++) {
    if (currA == NULL) {
      return;
    }
    currA = currA->next;
  }

  for (int i = 0; i < skipB; i++) {
    if (currB == NULL) {
      return;
    }
    currB = currB->next;
  }

  while (currB->next != NULL) {
    currB = currB->next;
  }

  currB->next = currA;
}

void freeLinkedList(struct ListNode* head) {
  struct ListNode* tmp;
  while (head != NULL) {
    tmp = head;
    head = head->next;
    free(tmp);
  }
}

struct ListNode* getIntersectionNode(struct ListNode* headA,
                                     struct ListNode* headB) {
  struct ListNode* currA = headA;
  struct ListNode* currB = headB;

  int lenA = 0, lenB = 0;
  while (currA != NULL) {
    lenA++;
    currA = currA->next;
  }
  while (currB != NULL) {
    lenB++;
    currB = currB->next;
  }

  currA = headA;
  currB = headB;

  if (lenA >= lenB) {
    for (int i = 0; i < lenA - lenB; i++) {
      currA = currA->next;
    }
  } else {
    for (int i = 0; i < lenB - lenA; i++) {
      currB = currB->next;
    }
  }

  while (1) {
    if (currA == currB) {
      return currA;
    }
    if (currA->next == NULL || currB->next == NULL) {
      break;
    }
    currA = currA->next;
    currB = currB->next;
  }

  return NULL;
}