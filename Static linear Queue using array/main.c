#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

typedef struct Queue {
    int items[MAXSIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = -1; // Indicates the front of the queue
    q->rear = -1;  // Indicates the rear of the queue
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return (q->rear + 1) % MAXSIZE == q->front;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to insert an element into the queue
void insert(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0; // Set front to 0 if inserting the first element
    }
    q->rear = (q->rear + 1) % MAXSIZE; // Circular increment
    q->items[q->rear] = value;
    printf("Inserted %d into the queue\n", value);
}

// Function to delete an element from the queue
int delete(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot delete from an empty queue\n");
        return -1; // Return -1 to indicate underflow
    }
    int deletedValue = q->items[q->front];
    if (q->front == q->rear) {
        // Queue has only one element, reset the queue
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAXSIZE; // Circular increment
    }
    return deletedValue;
}

// Function to display the elements of the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) {
            break;
        }
        i = (i + 1) % MAXSIZE; // Circular increment
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    // Testing the queue with insert and delete operations
    insert(&q, 10);
    insert(&q, 20);
    insert(&q, 30);
    display(&q); // Display after inserting 3 elements

    int deletedValue = delete(&q);
    if (deletedValue != -1) {
        printf("Deleted %d from the queue\n", deletedValue);
    }

    deletedValue = delete(&q);
    if (deletedValue != -1) {
        printf("Deleted %d from the queue\n", deletedValue);
    }

    display(&q); // Display after deleting 2 elements

    // Attempting to insert another element
    insert(&q, 40);
    display(&q); // Display after inserting another element

    // Attempting to insert when queue is full
    insert(&q, 50);
    insert(&q, 60); // This should trigger overflow

    return 0;
}
