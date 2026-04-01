/*
 * TOPIC: Array Traversal — Best Time to Buy and Sell Stock
 * LeetCode #121 — Easy
 * --------------------------------------------------------
 * Problem: Given an array where prices[i] is the price of
 * a stock on day i, find the maximum profit you can achieve
 * by buying on one day and selling on a later day.
 *
 * Example:
 *   Input:  {7, 1, 5, 3, 6, 4}
 *   Output: 5  (buy at 1, sell at 6)
 *
 * Logic: Track the minimum price seen so far.
 * On each day, calculate profit if you sold today.
 * Update max profit accordingly.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 */

#include <stdio.h>
#include <limits.h>

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n        = sizeof(prices) / sizeof(prices[0]);

    int minPrice  = INT_MAX; // lowest buy price seen so far
    int maxProfit = 0;       // best profit seen so far

    for (int i = 0; i < n; i++) {
        if (prices[i] < minPrice)
            minPrice = prices[i];         // update min buy price
        else if (prices[i] - minPrice > maxProfit)
            maxProfit = prices[i] - minPrice; // update max profit
    }

    printf("Maximum Profit = %d\n", maxProfit);

    return 0;
}