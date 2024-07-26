#include <stdbool.h>
#include <stdio.h>

int BAD;

bool isBadVersion(int version);
int firstBadVersion(int n);

int main() {
  // declaration
  int num, res;

  // input
  printf("\nEnter the bad version: ");
  scanf("%d", &BAD);
  printf("Enter n: ");
  scanf("%d", &num);

  // processing
  res = firstBadVersion(num);

  // output
  printf("\nResult: \n");
  printf("Version %d is the first bad version\n\n", res);

  return 0;
}

bool isBadVersion(int version) { return version == BAD; }

int firstBadVersion(int n) {
  int left = 1, right = n, mid;
  while (left < right) {
    mid = left + (right - left) / 2;
    if (isBadVersion(mid)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}