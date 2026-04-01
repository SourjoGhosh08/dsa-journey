/*
 * TOPIC: Array Traversal — Second Largest Element
 * ------------------------------------------------
 * Problem: Find the second largest element in an array
 * without sorting it.
 *
 * Example:
 *   Input:  {12, 35, 1, 10, 34, 1}
 *   Output: Second Largest = 34
 *
 * Logic: Track both the largest and second largest.
 * On each element, update second largest before updating largest.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 */

#include <stdio.h>
#include <limits.h>

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int first  = INT_MIN; // largest
    int second = INT_MIN; // second largest

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;  // old largest becomes second
            first  = arr[i]; // update largest
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i]; // update second largest
        }
    }

    if (second == INT_MIN)
        printf("No second largest element\n");
    else
        printf("Second Largest = %d\n", second);

    return 0;
}