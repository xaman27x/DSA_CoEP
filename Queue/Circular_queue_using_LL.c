// Circular Queue using Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue() {
    int x;
    printf("Enter Data to be Enqueued\n");
    scanf("%d", &x);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    if (!rear) {
        front = rear = newNode;
        rear->next = front;
    }
    else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    return;
}

void dequeue() {
    struct Node *temp = front;
    if (!front && !rear) {
        printf("Queue is empty\n");
        return;
    }
    else if (front == rear) {
        front = rear = NULL;
        free(temp);
    }
    else {
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void peek() {
    if (!front && !rear) {
        printf("Queue is empty\n");
        return;
    }
    else {
        printf("Top Element is %d\n", front->data);
    }
    return;
}

void display() {
    struct Node *temp = front;
    if (!front && !rear) {
        printf("Queue is Empty\n");
        return;
    }
    else {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp->next != front->next);
    }
    printf("\n");
    return;
}

int main() {
    int ch;
    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Peek\n5.Exit");
        printf("\nEnter your choice(1-4):");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid Option\n");
        }
    }
    return 0;
}