/*
 * TOPIC: Stack Using Array — Push, Pop, Peek
 * ------------------------------------------
 * Problem: Implement a stack from scratch using an array.
 * Support push (insert), pop (remove), and peek (view top).
 *
 * Example:
 *   Push 10, 20, 30
 *   Peek  → 30
 *   Pop   → 30
 *   Peek  → 20
 *
 * Logic: Use an array with a variable 'top' that tracks
 * the index of the topmost element. Start top at -1 (empty).
 *
 * Time Complexity:  O(1) for all operations
 * Space Complexity: O(n)
 */

#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1; // -1 means stack is empty

// push element onto stack
void push(int val) {
    if (top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = val;
    printf("Pushed %d\n", val);
}

// pop element from stack
void pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        return;
    }
    printf("Popped %d\n", stack[top--]);
}

// peek at top element
void peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top = %d\n", stack[top]);
}

int main() {
    int choice, val;

    printf("Stack Operations:\n");
    printf("1. Push\n2. Pop\n3. Peek\n4. Exit\n\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}