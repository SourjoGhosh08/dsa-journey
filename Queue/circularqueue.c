/*
 * TOPIC: Circular Queue
 * ---------------------
 * Problem: Implement a circular queue that reuses empty
 * spaces at the front after dequeue operations.
 * Normal queue wastes space — circular queue fixes that.
 *
 * Example:
 *   Enqueue 10, 20, 30
 *   Dequeue → 10  (front space is now reusable)
 *   Enqueue 40   (fills the freed space circularly)
 *
 * Logic: Use modulo (%) to wrap front and rear pointers
 * around the array instead of going out of bounds.
 *
 * Time Complexity:  O(1) for all operations
 * Space Complexity: O(n)
 */

#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear  = -1;

int isFull()  { return (rear + 1) % MAX == front; }
int isEmpty() { return front == -1; }

void enqueue(int val) {
    if (isFull()) {
        printf("Circular queue is full!\n");
        return;
    }
    if (isEmpty()) front = 0;
    rear = (rear + 1) % MAX; // wrap around
    queue[rear] = val;
    printf("Enqueued %d\n", val);
}

void dequeue() {
    if (isEmpty()) {
        printf("Circular queue is empty!\n");
        return;
    }
    printf("Dequeued %d\n", queue[front]);
    if (front == rear)  // last element removed
        front = rear = -1;
    else
        front = (front + 1) % MAX; // wrap around
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Front = %d\n", queue[front]);
}

int main() {
    int choice, val;

    printf("Circular Queue Operations:\n");
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
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