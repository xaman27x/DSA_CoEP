// Queue Using Linked List
#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int data;
    struct Queue *next;
};

struct Queue *front = NULL;
struct Queue *rear = NULL;

void enqueue(int x) {
    struct Queue *newNode = (struct Queue *)malloc(sizeof(struct Queue));
    newNode->data = x;
    newNode->next = NULL;
    if (!front && !rear) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
    return;
}

void dequeue() {
    struct Queue *temp = front;
    if (!front && !rear) {
        printf("Queue is empty\n");
    }
    else {
        printf("Element dequeued is %d\n", front->data);
        front = front->next;
        free(temp);
    }
    return;
}

void peek() {
    if (!front && !rear) {
        printf("Queue is empty\n");
    }
    else {
        printf("Top Element is %d\n", front->data);
    }
    return;
}

void display() {
    struct Queue *temp = front;
    if (front == NULL && rear == NULL) {
        printf("Queue is empty\n");
    }
    else {
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    return;
}

int main() {
    int opt, value, popped = 0;
    while (1) {
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");

        scanf("%d", &opt);

        switch (opt) {
        case 1:
            printf("enter the value\n");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        }
    }
    return 0;
}
