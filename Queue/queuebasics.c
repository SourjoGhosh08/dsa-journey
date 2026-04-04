/*
 * TOPIC: Queue Using Array — Enqueue, Dequeue, Peek
 * --------------------------------------------------
 * Problem: Implement a queue from scratch using an array.
 * Support enqueue (insert at rear), dequeue (remove from front),
 * and peek (view front element).
 *
 * Example:
 *   Enqueue 10, 20, 30
 *   Peek   → 10
 *   Dequeue → 10
 *   Peek   → 20
 *
 * Logic: Use two pointers — front and rear.
 * front tracks where to remove, rear tracks where to insert.
 *
 * Time Complexity:  O(1) for all operations
 * Space Complexity: O(n)
 */

#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear  = -1;

void enqueue(int val) {
    if (rear == MAX - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1) front = 0; // first element
    queue[++rear] = val;
    printf("Enqueued %d\n", val);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Dequeued %d\n", queue[front++]);
}

void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Front = %d\n", queue[front]);
}

int main() {
    int choice, val;

    printf("Queue Operations:\n");
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
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