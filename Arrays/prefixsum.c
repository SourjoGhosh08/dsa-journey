/*
 * TOPIC: Prefix Sum
 * -----------------
 * Problem: Given an array, answer multiple range sum queries.
 * Find the sum of elements between index l and r (inclusive).
 *
 * Example:
 *   Input:  arr = {2, 4, 6, 8, 10}, l = 1, r = 3
 *   Output: Sum = 18  (4 + 6 + 8)
 *
 * Logic: Build a prefix sum array where prefix[i] = sum of
 * all elements from index 0 to i. Then any range sum
 * l to r = prefix[r] - prefix[l-1].
 *
 * Time Complexity:  O(n) to build, O(1) per query
 * Space Complexity: O(n)
 */

#include <stdio.h>

int main() {
    int arr[]  = {2, 4, 6, 8, 10};
    int n      = sizeof(arr) / sizeof(arr[0]);
    int prefix[n];

    // build prefix sum array
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    // query: sum from index l to r
    int l = 1, r = 3;
    int sum = (l == 0) ? prefix[r] : prefix[r] - prefix[l - 1];

    printf("Sum from index %d to %d = %d\n", l, r, sum);

    return 0;
}