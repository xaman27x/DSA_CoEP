#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 256

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int* A, int len) {
    for(int i = 0; i < len; i++) {
        for(int j = i; j < len; j++) {
            if(A[i] > A[j]) swap(&A[i], &A[j]);
        }
    };
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
    selectionSort(A, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
