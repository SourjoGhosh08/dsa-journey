/*
 * TOPIC: Two Pointer — Move Zeros to End
 * LeetCode #283 — Easy
 * --------------------------------------
 * Problem: Move all 0s to the end of the array
 * while maintaining the order of non-zero elements.
 *
 * Example:
 *   Input:  {0, 1, 0, 3, 12}
 *   Output: {1, 3, 12, 0, 0}
 *
 * Logic: Use a pointer to track where the next non-zero
 * element should go. Skip zeros, place non-zeros in order,
 * then fill the rest with zeros.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 */

#include <stdio.h>

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int n     = sizeof(arr) / sizeof(arr[0]);

    int pos = 0; // position for next non-zero element

    // place all non-zero elements first
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[pos++] = arr[i];
        }
    }

    // fill remaining positions with zero
    while (pos < n) {
        arr[pos++] = 0;
    }

    printf("After moving zeros: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}