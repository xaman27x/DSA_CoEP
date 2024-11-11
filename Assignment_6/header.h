#ifndef MINHEAP_SORT
#define MINHEAP_SORT

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity);
void insert(MinHeap *heap, int value);
int extractMin(MinHeap *heap);
void minHeapify(MinHeap *heap, int i);
void displaySortedOrder(MinHeap *heap);
void freeHeap(MinHeap *heap);

#endif // MINHEAP_SORT
