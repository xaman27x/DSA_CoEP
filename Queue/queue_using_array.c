#include <stdio.h>
#include <stdlib.h>

#define N 50

struct Queue {
    int data[N];
    int front;
    int rear;
};

void init(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

void enqueue(struct Queue *q) {
    int x;
    printf("Enter the Element to be inserted:\n");
    scanf("%d", &x);

    if (q->rear == N - 1) {
        printf("Queue is Full!\n");
    } else if (q->front == -1 && q->rear == -1) {
        q->rear = q->front = 0;
        q->data[q->rear] = x;
    } else {
        q->rear++;
        q->data[q->rear] = x;
    }
}

void dequeue(struct Queue *q) {
    if (q->front == -1 && q->rear == -1) {
        printf("Queue is Empty!\n");
    } else if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
}

void display(struct Queue *q) {
    if (q->front == -1 && q->rear == -1) {
        printf("Queue is Empty\n");
    } else {
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->data[i]);
        }
        printf("\n");
    }
}

void peek(struct Queue *q) {
    if (q->front == -1 && q->rear == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Front Element: %d\n", q->data[q->front]);
    }
}

int main() {
    struct Queue q;
    init(&q);

    int ch;

    while (1) {
        printf("\n*** Queue Menu ***\n");
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Peek\n5. Exit\n");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                enqueue(&q);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                peek(&q);
                break;
            case 5:
                exit(0);
            default:
                printf("\nWrong Choice!\n");
        }
    }

    return 0;
}
