/*
 * TOPIC: Sliding Window (Fixed) — Maximum Average Subarray I
 * LeetCode #643 — Easy
 * ----------------------------------------------------------
 * Problem: Find a contiguous subarray of length k
 * that has the maximum average value.
 *
 * Example:
 *   Input:  arr = {1, 12, -5, -6, 50, 3}, k = 4
 *   Output: 12.75  (subarray: {12, -5, -6, 50} / 4)
 *
 * Logic: Calculate the sum of the first window of size k.
 * Then slide the window — add the next element, remove the first.
 * Track the maximum sum throughout.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 */

#include <stdio.h>

int main() {
    int arr[] = {1, 12, -5, -6, 50, 3};
    int n     = sizeof(arr) / sizeof(arr[0]);
    int k     = 4;

    // sum of first window
    int windowSum = 0;
    for (int i = 0; i < k; i++)
        windowSum += arr[i];

    int maxSum = windowSum;

    // slide the window
    for (int i = k; i < n; i++) {
        windowSum += arr[i];         // add new element on right
        windowSum -= arr[i - k];     // remove element on left
        if (windowSum > maxSum)
            maxSum = windowSum;
    }

    printf("Maximum Average = %.2f\n", (double)maxSum / k);

    return 0;
}