#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Helper functions
static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static int parentIndex(int i) {
    return (i - 1) / 2;
}

static int leftChildIndex(int i) {
    return 2 * i + 1;
}

static int rightChildIndex(int i) {
    return 2 * i + 2;
}

static void heapifyDown(Heap *heap, int index) {
    int left = leftChildIndex(index);
    int right = rightChildIndex(index);
    int extreme = index;

    // Determine the extreme (max or min) among parent and children
    if (heap->isMaxHeap) {
        if (left < heap->size && heap->data[left] > heap->data[extreme])
            extreme = left;
        if (right < heap->size && heap->data[right] > heap->data[extreme])
            extreme = right;
    } else {
        if (left < heap->size && heap->data[left] < heap->data[extreme])
            extreme = left;
        if (right < heap->size && heap->data[right] < heap->data[extreme])
            extreme = right;
    }

    if (extreme != index) {
        swap(&heap->data[index], &heap->data[extreme]);
        heapifyDown(heap, extreme);
    }
}

static void heapifyUp(Heap *heap, int index) {
    while (index > 0 && ((heap->isMaxHeap && heap->data[index] > heap->data[parentIndex(index)]) ||
                         (!heap->isMaxHeap && heap->data[index] < heap->data[parentIndex(index)]))) {
        swap(&heap->data[index], &heap->data[parentIndex(index)]);
        index = parentIndex(index);
    }
}

Heap* createHeap(int capacity, bool isMaxHeap) {
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    if (!heap) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    heap->data = (int *)malloc(capacity * sizeof(int));
    if (!heap->data) {
        fprintf(stderr, "Memory allocation failed\n");
        free(heap);
        exit(EXIT_FAILURE);
    }
    heap->size = 0;
    heap->capacity = capacity;
    heap->isMaxHeap = isMaxHeap;
    return heap;
}

void insertHeap(Heap *heap, int value) {
    if (heap->size == heap->capacity) {
        fprintf(stderr, "Heap overflow\n");
        return;
    }
    heap->data[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
}

int extractRoot(Heap *heap) {
    if (heap->size == 0) {
        fprintf(stderr, "Heap underflow\n");
        return heap->isMaxHeap ? INT_MIN : INT_MAX;
    }
    int root = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    heapifyDown(heap, 0);
    return root;
}

int peek(Heap *heap) {
    if (heap->size == 0) {
        fprintf(stderr, "Heap is empty\n");
        return heap->isMaxHeap ? INT_MIN : INT_MAX;
    }
    return heap->data[0];
}

bool isEmpty(Heap *heap) {
    return heap->size == 0;
}

void destroyHeap(Heap *heap) {
    if (heap) {
        free(heap->data);
        free(heap);
    }
}
