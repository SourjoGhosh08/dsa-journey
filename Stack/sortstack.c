/*
 * TOPIC: Stack — Sort a Stack
 * ----------------------------
 * Problem: Sort a stack so that the smallest element
 * is on top, using only stack operations (no arrays for sorting).
 *
 * Example:
 *   Input Stack (top to bottom):  {3, 1, 4, 2}
 *   Output Stack (top to bottom): {1, 2, 3, 4}
 *
 * Logic: Use a temporary stack. For each element popped
 * from the original stack, find its correct position in
 * the temp stack by moving elements back if needed.
 *
 * Time Complexity:  O(n^2)
 * Space Complexity: O(n)
 */

#include <stdio.h>
#define MAX 100

// original stack
int stack[MAX];
int top = -1;

// temporary stack
int temp[MAX];
int tempTop = -1;

void push(int* s, int* t, int val)  { s[++(*t)] = val; }
int  pop(int* s, int* t)            { return s[(*t)--]; }
int  isEmpty(int t)                 { return t == -1; }
int  peek(int* s, int t)            { return s[t]; }

void sortStack() {
    while (!isEmpty(top)) {
        int curr = pop(stack, &top); // take element from original

        // move elements from temp back to original if they are smaller
        while (!isEmpty(tempTop) && peek(temp, tempTop) < curr) {
            push(stack, &top, pop(temp, &tempTop));
        }

        push(temp, &tempTop, curr); // place in correct position in temp
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements to push (bottom to top): ");
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        push(stack, &top, val);
    }

    sortStack();

    printf("Sorted stack (top to bottom): ");
    while (!isEmpty(tempTop))
        printf("%d ", pop(temp, &tempTop));
    printf("\n");

    return 0;
}