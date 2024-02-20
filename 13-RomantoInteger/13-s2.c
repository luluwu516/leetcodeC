#include <stdio.h>

// Hashtable solution from bezlant
// https://leetcode.com/problems/roman-to-integer/solutions/1960876/c-100-hashtable-solution-o-n
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
  int roman_to_int['X' + 1] = {
      ['I'] = 1,   ['V'] = 5,   ['X'] = 10,   ['L'] = 50,
      ['C'] = 100, ['D'] = 500, ['M'] = 1000,
  };

  int sum = 0;
  for (int i = 0; s[i]; i++) {
    if (roman_to_int[s[i]] < roman_to_int[s[i + 1]])
      sum -= roman_to_int[s[i]];
    else
      sum += roman_to_int[s[i]];
  }

  return sum;
}