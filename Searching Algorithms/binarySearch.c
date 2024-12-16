#include <stdio.h>
#include <stdlib.h>

int binarySearch(int* A, int len, int target) {
    int mid;
    int l = 0;
    int r = len - 1;
    
    while(l <= r) {
        mid = (l + r) / 2;

        if(mid == target) {
            return mid;
        } else if(mid < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    };
    return -1;
}

int main() {
    int len, target;
    scanf("%d %d", &len, &target);
    
    int* A = (int*) malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        scanf("%d", &A[i]);
    }
    
    int index = binarySearch(A, len, target);
    printf("%d\n", index);
    
    free(A);
    return 0;
}