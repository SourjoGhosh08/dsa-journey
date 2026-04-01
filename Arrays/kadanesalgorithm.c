/*
 * TOPIC: Kadane's Algorithm — Maximum Subarray Sum
 * LeetCode #53 — Medium
 * -------------------------------------------------
 * Problem: Find the contiguous subarray with the largest sum.
 *
 * Example:
 *   Input:  {-2, 1, -3, 4, -1, 2, 1, -5, 4}
 *   Output: 6  (subarray: {4, -1, 2, 1})
 *
 * Logic: Keep a running sum. If adding current element
 * makes it negative, reset to 0. Track the maximum seen so far.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 */

#include <stdio.h>

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n     = sizeof(arr) / sizeof(arr[0]);

    int maxSum     = arr[0]; // stores final answer
    int currentSum = arr[0]; // running sum

    for (int i = 1; i < n; i++) {
        // either extend current subarray or start fresh
        if (currentSum + arr[i] > arr[i])
            currentSum = currentSum + arr[i];
        else
            currentSum = arr[i];

        if (currentSum > maxSum)
            maxSum = currentSum; // update best answer
    }

    printf("Maximum Subarray Sum = %d\n", maxSum);

    return 0;
}