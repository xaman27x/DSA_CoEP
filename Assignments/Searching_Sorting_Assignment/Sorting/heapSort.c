#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 256

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* A, int len, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < len && A[l] > A[largest]) largest = l;
    if (r < len && A[r] > A[largest]) largest = r;

    if (largest != i) {
        swap(&A[i], &A[largest]);
        heapify(A, len, largest); 
    }
}

void heapSort(int* A, int len) {

    for (int i = len / 2 - 1; i >= 0; i--) heapify(A, len, i);

    for (int i = len - 1; i > 0; i--) {
        swap(&A[0], &A[i]); 
        heapify(A, i, 0); 
    }
}

int main() {
    char buffer[MAX_SIZE];
    int A[50000];
    int len = 0;
    FILE *fd = fopen("random_integers_50000.csv", "r");
    if (!fd) {
        perror("Error Opening the File");
        return 1;
    }

    fgets(buffer, MAX_SIZE, fd);

    while (fgets(buffer, MAX_SIZE, fd)) {
        int index;
        int value;

        if (sscanf(buffer, "%d,%f", &index, &value) == 2) {
            A[len++] = value;
        }
    }

    fclose(fd);
    heapSort(A, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
