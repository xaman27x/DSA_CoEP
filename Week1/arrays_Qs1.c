#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Enter Size of Array: ");
    scanf("%d", &size);
    int* arr = (int*) malloc(size * sizeof(int));
    for(int i = 0; i < size; i++) {
        scanf(" %d", &arr[i]);
    }
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                for(int m = j; m < size - 1; m++) {
                    arr[m] = arr[m + 1];
                };
                size--;
                j--;
            }
        }
    }
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
    return 0;
}