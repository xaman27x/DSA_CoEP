#include <stdio.h>
#include <stdlib.h>

int linearSearch(int* A, int len, int target) {
    for (int i = 0; i < len; i++) {
        if (A[i] == target) return i;
    }
    return -1;
}

int main() {
    int len, target;
    scanf("%d %d", &len, &target);
    
    int* A = (int*) malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        scanf("%d", &A[i]);
    }
    
    int index = linearSearch(A, len, target);
    printf("%d\n", index);
    
    free(A);
    return 0;
}
