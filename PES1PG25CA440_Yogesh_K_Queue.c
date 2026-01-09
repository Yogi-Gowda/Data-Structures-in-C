#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct myqueue {
    int queue[MAX];
    int front;
    int rear;
} Queue;

int isEmpty(Queue *q) {
    return q->rear == -1;
}

int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->queue[q->rear] = value;
    printf("Inserted %d\n", value);
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
    }
    else{
        int value = q->queue[q->front];
        q->front++;
        if(q->front > q->rear){
            q->front = q->rear = -1;
        }
        return value;
    }
}

int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        return q->queue[q->front];
    }
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->queue[i]);
    }
}

int main() {
    Queue q;
    q.front = -1;
    q.rear = -1;

    enqueue(&q, 5);
    enqueue(&q, 15);
    enqueue(&q, 20);
    display(&q);

    printf("\nPeek element: %d\n", peek(&q));
    printf("Deleted: %d\n", dequeue(&q));
    display(&q);

    printf("\nPeek element: %d\n", peek(&q));
    return 0;
}
