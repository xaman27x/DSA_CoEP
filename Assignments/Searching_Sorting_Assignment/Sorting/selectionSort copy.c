#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 512

void swap(float* a, float* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(float* A, int len) {
    for(int i = 0; i < len; i++) {
        for(int j = i; j < len; j++) {
            if(A[i] > A[j]) swap(&A[i], &A[j]);
        }
    };
}

void main() {
    char buffer[MAX_SIZE];
    float A[1000];
    int len = 0;
    FILE* fd = fopen("random_numbers_1000.csv", "r");
    if(!fd) {
        perror("Error Opening the File");
        return;
    }
    fgets(buffer, MAX_SIZE, fd);
    while(fgets(buffer, MAX_SIZE, fd)) {
        char* p = strtok(buffer, ",");
        p = strtok(NULL, "\n");
        A[len++] = atof(p);
    }
    selectionSort(A, len);
        for (int i = 0; i < len; i++) {
        printf("%f ", A[i]);
    }
    return;
}