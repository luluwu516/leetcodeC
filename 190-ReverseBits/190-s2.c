#include "inttypes.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

uint32_t reverseBits(uint32_t n);

int main() {
  // declaration
  uint32_t num;
  char input[33];
  uint32_t res;

  // input
  printf("\nEnter the binary number: ");
  scanf("%32s", input);

  char *endptr;
  num = strtoul(input, &endptr, 2);
  printf("nums: %" PRIu32 "\n", num);

  // processing
  res = reverseBits(num);

  // output
  printf("\n\nResult:\n");
  printf("The return number in decimal representation is '%d'\n\n", res);

  return 0;
}

uint32_t reverseBits(uint32_t n) {
  uint32_t res = 0;

  for (int i = 0; i < 31; i++) {
    res = ((n % 2) + res) << 1;
    n >>= 1;
  }

  return res + n % 2;
}