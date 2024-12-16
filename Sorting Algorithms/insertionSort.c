#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 256

void insertionSort(int* A, int len) {
    int key;
    for(int i = 1; i < len; i++) {
        key = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
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
        float value;

        if (sscanf(buffer, "%d,%f", &index, &value) == 2) {
            A[len++] = value;
        }
    }

    fclose(fd);
    insertionSort(A, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}