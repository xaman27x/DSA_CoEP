#include "header.h"

MinHeap* createHeap(int capacity) {
    MinHeap *heap = (MinHeap*) malloc(sizeof(MinHeap));
    heap->data = (int*) malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void insert(MinHeap *heap, int value) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->data = (int*) realloc(heap->data, heap->capacity * sizeof(int));
    }

    int i = heap->size;
    heap->data[i] = value;
    heap->size++;

    while (i != 0 && heap->data[i] < heap->data[(i - 1) / 2]) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[(i - 1) / 2];
        heap->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int extractMin(MinHeap *heap) {
    if (heap->size <= 0) {
        return -1;
    }
    if (heap->size == 1) {
        heap->size--;
        return heap->data[0];
    }

    int root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);

    return root;
}

// Function to maintain the MinHeap
void minHeapify(MinHeap *heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->data[left] < heap->data[smallest]) {
        smallest = left;
    }
    if (right < heap->size && heap->data[right] < heap->data[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[smallest];
        heap->data[smallest] = temp;
        minHeapify(heap, smallest);
    }
}

void displaySortedOrder(MinHeap *heap) {
    while (heap->size > 0) {
        printf("%d ", extractMin(heap));
    }
    printf("\n");
}

void freeHeap(MinHeap *heap) {
    free(heap->data);
    free(heap);
}
