#include <stdio.h>
#include <stdlib.h>

#define N 50

struct CircularQueue {
    int data[N];
    int front;
    int rear;
};

void init(struct CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
    return;
}

void enqueue(struct CircularQueue *q) {
    int x;
    printf("Enter data");
    scanf("%d", &x);

    if ((q->rear + 1) % N == q->front) {
        return;
    } else if (q->front == -1 && q->rear == -1) {
        q->front = q->rear = 0;
        q->data[q->rear] = x;
    } else {
        q->rear = (q->rear + 1) % N;
        q->data[q->rear] = x;
    }
    return;
}

void dequeue(struct CircularQueue *q) {
    if (q->front == -1 && q->rear == -1) {
        return;
    } else if (q->front == q->rear) {
        printf("\nThe Dequeued element is %d\n", q->data[q->front]);
        q->front = q->rear = -1;
    } else {
        printf("\nThe Dequeued element is %d\n", q->data[q->front]);
        q->front = (q->front + 1) % N;
    }
    return;
}

void display(struct CircularQueue *q) {
    if (q->front == -1 && q->rear == -1) {
        return;
    } else {
        int i = q->front;
        while (i != q->rear) {
            printf("%d ", q->data[i]);
            i = (i + 1) % N;
        }
        printf("%d ", q->data[q->rear]);
        printf("\n");
    }
    return;
}

void peek(struct CircularQueue *q) {
    if (q->front == -1 && q->rear == -1) {
        return;
    } else {
        printf("%d\n", q->data[q->front]);
    }
    return;
}

int main() {
    struct CircularQueue q;
    init(&q);
    int ch;
    while (1) {
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
