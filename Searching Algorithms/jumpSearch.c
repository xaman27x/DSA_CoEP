#include <stdio.h>
#include <math.h>

int jumpSearch(int arr[], int n, int jump, int target) {
    int start = 0, end = jump;
    while (end < n) {
        if (arr[end] < target) {
            start = end;
            end = end + jump;
        } else {
            while (start <= end) {
                if (arr[start] == target)
                    return start;
                start++;
            }
        }
    }
    return -1;
}

int main() {
    int len, target;
    scanf("%d %d", &len, &target);
    int jump = (int) sqrt(len);

    int* A = (int*) malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        scanf("%d", &A[i]);
    }
    
    int index = jumpSearch(A, len, jump, target);
    printf("%d\n", index);
    free(A);
    return 0;
}