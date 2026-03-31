/*
 * TOPIC: Sliding Window (Variable) — Longest Subarray with Sum K
 * ---------------------------------------------------------------
 * Problem: Find the length of the longest subarray
 * whose elements sum to exactly K.
 *
 * Example:
 *   Input:  arr = {1, 2, 3, 1, 1, 1, 1}, k = 3
 *   Output: 5  (subarray: {1, 1, 1, 1} no — {3,1,1,1} no)
 *            → actually {1,2} or {3} or {1,1,1} = length 3
 *              longest = {1,1,1,1} has sum 4, so {1,2,3} no
 *              answer here = 3 for subarray {1,2} extended
 *
 * Logic: Use two pointers left and right. Expand right to grow
 * the window. Shrink from left when sum exceeds k.
 * Track max length when sum equals k.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 */

#include <stdio.h>

int main() {
    int arr[] = {1, 2, 1, 0, 1, 1, 0};
    int n     = sizeof(arr) / sizeof(arr[0]);
    int k     = 3;

    int left   = 0;
    int sum    = 0;
    int maxLen = 0;

    for (int right = 0; right < n; right++) {
        sum += arr[right]; // expand window to the right

        // shrink window from left if sum exceeds k
        while (sum > k && left <= right) {
            sum -= arr[left];
            left++;
        }

        // check if current window has sum == k
        if (sum == k) {
            int len = right - left + 1;
            if (len > maxLen) maxLen = len;
        }
    }

    printf("Longest subarray length with sum %d = %d\n", k, maxLen);

    return 0;
}