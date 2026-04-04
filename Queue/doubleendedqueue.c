/*
 * TOPIC: Deque — Double Ended Queue
 * ----------------------------------
 * Problem: Implement a deque where insertion and deletion
 * can happen from BOTH front and rear ends.
 *
 * Example:
 *   Insert front: 10 → [10]
 *   Insert rear:  20 → [10, 20]
 *   Insert front: 5  → [5, 10, 20]
 *   Delete rear      → [5, 10]
 *   Delete front     → [10]
 *
 * Logic: Use an array with front and rear pointers.
 * insertFront decrements front, insertRear increments rear.
 * Use circular logic with modulo to avoid overflow.
 *
 * Time Complexity:  O(1) for all operations
 * Space Complexity: O(n)
 */

#include <stdio.h>
#define MAX 10

int deque[MAX];
int front = -1;
int rear  = -1;

int isFull()  { return (rear + 1) % MAX == front; }
int isEmpty() { return front == -1; }

void insertRear(int val) {
    if (isFull()) { printf("Deque is full!\n"); return; }
    if (isEmpty()) front = 0;
    rear = (rear + 1) % MAX;
    deque[rear] = val;
    printf("Inserted %d at rear\n", val);
}

void insertFront(int val) {
    if (isFull()) { printf("Deque is full!\n"); return; }
    if (isEmpty()) { front = 0; rear = 0; }
    else front = (front - 1 + MAX) % MAX; // wrap backward
    deque[front] = val;
    printf("Inserted %d at front\n", val);
}

void deleteFront() {
    if (isEmpty()) { printf("Deque is empty!\n"); return; }
    printf("Deleted from front: %d\n", deque[front]);
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
}

void deleteRear() {
    if (isEmpty()) { printf("Deque is empty!\n"); return; }
    printf("Deleted from rear: %d\n", deque[rear]);
    if (front == rear) front = rear = -1;
    else rear = (rear - 1 + MAX) % MAX;
}

void peekFront() {
    if (isEmpty()) { printf("Deque is empty!\n"); return; }
    printf("Front = %d\n", deque[front]);
}

int main() {
    int choice, val;

    printf("Deque Operations:\n");
    printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n");
    printf("4. Delete Rear\n5. Peek Front\n6. Exit\n\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertFront(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertRear(val);
                break;
            case 3: deleteFront(); break;
            case 4: deleteRear();  break;
            case 5: peekFront();   break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}