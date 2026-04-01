/*
 * TOPIC: Two Pointer — Two Sum
 * LeetCode #1 — Easy
 * ----------------------------
 * Problem: Given an array of integers and a target,
 * return the indices of the two numbers that add up to target.
 *
 * Example:
 *   Input:  arr = {2, 7, 11, 15}, target = 9
 *   Output: Indices 0 and 1 (2 + 7 = 9)
 *
 * Logic: Use a nested loop. For each element, check if
 * any other element adds up to the target.
 *
 * Time Complexity:  O(n^2)
 * Space Complexity: O(1)
 */

#include <stdio.h>

int main() {
    int arr[]  = {2, 7, 11, 15};
    int n      = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("Indices: %d and %d\n", i, j);
                return 0;
            }
        }
    }

    printf("No two sum found\n");
    return 0;
}