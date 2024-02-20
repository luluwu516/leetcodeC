#include <stdio.h>
#include <string.h>

int romanToInt(char* s);

int main() {
  // Declaration
  char roman_numeral[20];

  // Input
  printf("Enter Roman numeral (I, V, X, L, C, D, or M): ");
  scanf("%s", roman_numeral);

  // Processing and Output
  printf("\nResult: %d\n", romanToInt(roman_numeral));

  return 0;
}

int romanToInt(char* s) {
  int sum = 0, num = 0;
  int len = strlen(s);

  //   int prev = 0;
  //   for (int i = 0; i < len; i++) {
  //     switch (s[i]) {
  //       case 'I':
  //         num = 1;
  //         break;
  //       case 'V':
  //         num = 5;
  //         break;
  //       case 'X':
  //         num = 10;
  //         break;
  //       case 'L':
  //         num = 50;
  //         break;
  //       case 'C':
  //         num = 100;
  //         break;
  //       case 'D':
  //         num = 500;
  //         break;
  //       case 'M':
  //         num = 1000;
  //         break;
  //       default:
  //         num = 0;
  //         break;
  //     }

  //     if (num > prev) {
  //       sum += num;
  //       sum -= (prev * 2);
  //     } else
  //       sum += num;

  //     prev = num;
  //   }

  // Another way
  int num_right = 0;
  for (int i = len - 1; i >= 0; i--) {
    switch (s[i]) {
      case 'I':
        num = 1;
        break;
      case 'V':
        num = 5;
        break;
      case 'X':
        num = 10;
        break;
      case 'L':
        num = 50;
        break;
      case 'C':
        num = 100;
        break;
      case 'D':
        num = 500;
        break;
      case 'M':
        num = 1000;
        break;
      default:
        num = 0;
        break;
    }

    if (num < num_right) {
      sum -= num;
    } else
      sum += num;

    num_right = num;
  }

  return sum;
}