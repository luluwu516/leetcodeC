#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)

int maxProfit(int* prices, int pricesSize);

int main() {
  // declaration
  int size, res;

  // input
  printf("Enter the size of the prices: ");
  scanf("%d", &size);

  int prices[size];
  printf("Enter the the price: \n");
  for (int i = 0; i < size; i++) {
    printf("> ");
    scanf("%d", &prices[i]);
  }

  // processing
  res = maxProfit(prices, size);

  // output
  printf("\n\nResult:\n");
  printf("The maximum profit is: %d\n", res);

  return 0;
}

int maxProfit(int* prices, int pricesSize) {
  if (pricesSize < 2) {
    return 0;
  }

  int profit = 0;
  int buy_price = prices[0];
  for (int sell_day = 1; sell_day < pricesSize; sell_day++) {
    profit = MAX(profit, prices[sell_day] - buy_price);
    buy_price = MIN(buy_price, prices[sell_day]);
  }

  return profit;
}