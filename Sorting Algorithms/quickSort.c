#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int part(int* A, int low, int high) {
    int pivot = A[(low + high) / 2];
    int i = low - 1;
    int j = high + 1;

    while (1) {
        do {
            i++;
        } while (A[i] < pivot);

        do {
            j--;
        } while (A[j] > pivot);

        if (i >= j) return j;
        swap(&A[i], &A[j]);
    }
}

void quickSort(int* A, int low, int high) {
    if (low < high) {
        int x = part(A, low, high);
        quickSort(A, low, x);
        quickSort(A, x + 1, high);
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
        if (sscanf(buffer, "%d,%d", &index, &value) == 2) {
            A[len++] = value;
        }
    }

    fclose(fd);
    quickSort(A, 0, len - 1);

    for (int i = 0; i < len; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
