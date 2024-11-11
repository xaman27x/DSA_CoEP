#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

// Initialize the queue
void qinit(queue* q) {
    q->head = NULL;
    q->tail = NULL;
}

// Check if the queue is full
int qfull(queue* q) {
    // Test memory allocation by trying to malloc and free immediately
    node* temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        // malloc failed, so the queue is considered "full"
        return 1;
    }
    
    free(temp);
    return 0;
}

int qempty(queue* q) {
    return q->head == NULL;
}

void enq(queue* q, data d) {
    if (qfull(q)) {
        printf("Queue is full due to memory allocation failure, cannot enqueue.\n");
        return;
    }

    node* newNode = (node*)malloc(sizeof(node));
    if (!newNode) {
        printf("Memory allocation failed during enqueue.\n");
        return;
    }
    newNode->info = d;
    newNode->next = NULL;

    // If queue is empty, new node becomes both head and tail
    if (qempty(q)) {
        q->head = newNode;
        q->tail = newNode;
        newNode->next = q->head;  // Circular link: last node points to head
    } else {
        // Append new node to the tail and update tail pointer
        q->tail->next = newNode;
        q->tail = newNode;
        q->tail->next = q->head;
    }
}

// Dequeue an item
data deq(queue* q) {
    data temp = {"", 0};
    if (qempty(q)) {
        printf("Queue is empty.\n");
        return temp;
    }

    node* toDelete = q->head;
    temp = toDelete->info;

    if (q->head == q->tail) {
        q->head = NULL;
        q->tail = NULL;
    } else {
        q->head = q->head->next;
        q->tail->next = q->head;
    }

    free(toDelete);
    return temp;
}
