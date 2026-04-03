/*
 * TOPIC: Stack — Next Greater Element
 * LeetCode #496 — Easy
 * ------------------------------------
 * Problem: For each element in the array, find the next
 * element to its right that is greater than it.
 * If no such element exists, output -1.
 *
 * Example:
 *   Input:  {4, 5, 2, 10, 8}
 *   Output: {5, 10, 10, -1, -1}
 *
 * Logic: Traverse from right to left.
 * Use a stack to keep track of candidates.
 * Pop elements smaller than current — they can never be
 * the "next greater" for anything to the left.
 * Top of stack = next greater for current element.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(n)
 */

#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) { stack[++top] = val; }
int pop()          { return stack[top--]; }
int isEmpty()      { return top == -1; }
int peek()         { return stack[top]; }

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], result[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // pop all elements smaller than current
        while (!isEmpty() && peek() <= arr[i])
            pop();

        // next greater = top of stack, or -1 if empty
        result[i] = isEmpty() ? -1 : peek();

        push(arr[i]); // push current for elements to its left
    }

    printf("Next Greater Elements:\n");
    for (int i = 0; i < n; i++)
        printf("%d -> %d\n", arr[i], result[i]);

    return 0;
}