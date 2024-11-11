#include "header.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error");
        return 1;
    }

    MinHeap *heap = createHeap(100);

    int value;
    while (fscanf(file, "%d", &value) == 1) {
        insert(heap, value);
    }
    fclose(file);
    displaySortedOrder(heap);

    freeHeap(heap);
    return 0;
}

