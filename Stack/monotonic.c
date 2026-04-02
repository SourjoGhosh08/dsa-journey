/*
 * TOPIC: Monotonic Stack — Daily Temperatures
 * LeetCode #739 — Medium
 * -------------------------------------------
 * Problem: Given an array of daily temperatures, for each day
 * find how many days you have to wait until a warmer day.
 * If no future warmer day exists, output 0.
 *
 * Example:
 *   Input:  {73, 74, 75, 71, 69, 72, 76, 73}
 *   Output: {1,  1,  4,  2,  1,  1,  0,  0}
 *
 * Logic: Use a stack that stores indices (not values).
 * For each day, pop indices from the stack whose temperature
 * is less than today — today is their answer.
 * The stack stays in decreasing order (monotonic decreasing).
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(n)
 */

#include <stdio.h>
#define MAX 100

int stack[MAX]; // stores indices
int top = -1;

void push(int idx) { stack[++top] = idx; }
int pop()          { return stack[top--]; }
int isEmpty()      { return top == -1; }
int peek()         { return stack[top]; }

int main() {
    int n;
    printf("Enter number of days: ");
    scanf("%d", &n);

    int temps[n], result[n];

    printf("Enter temperatures: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &temps[i]);
        result[i] = 0; // default: no warmer day
    }

    for (int i = 0; i < n; i++) {
        // pop days that are cooler than today
        while (!isEmpty() && temps[peek()] < temps[i]) {
            int idx = pop();
            result[idx] = i - idx; // days waited
        }
        push(i); // push current day's index
    }

    printf("Days to wait for warmer temperature:\n");
    for (int i = 0; i < n; i++)
        printf("Day %d (%d°): %d days\n", i + 1, temps[i], result[i]);

    return 0;
}