#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 256

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int* A, int len) {
    int swapped;
    for(int i = 0; i < len - 1; i++) {
        swapped = 0;
        for(int j = 0; j < len - i - 1; j++) {
            if(A[j] > A[j + 1]) {
                swap(&A[j], &A[j + 1]);
                swapped = 1;
            }
        }
        if(!swapped) break;
    }
    return;
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
        float value;

        if (sscanf(buffer, "%d,%f", &index, &value) == 2) {
            A[len++] = value;
        }
    }

    fclose(fd);
    bubbleSort(A, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}