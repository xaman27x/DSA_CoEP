#ifndef HEAP_H
#define HEAP_H
#include <stdbool.h>

typedef struct {
    int *data;   
    int size;
    int capacity;
    bool isMaxHeap;
} Heap;

// Function prototypes
Heap* createHeap(int capacity, bool isMaxHeap);
void insertHeap(Heap *heap, int value);
int extractRoot(Heap *heap);
int peek(Heap *heap);
bool isEmpty(Heap *heap);
void destroyHeap(Heap *heap);

#endif // HEAP_H
