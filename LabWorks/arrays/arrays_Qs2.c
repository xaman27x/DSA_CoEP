#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[100];
    int result[100];
    int temp = 0;
    for(int i = 0; i < 100; i++) {
        arr[i] = rand() % 1000 + 1;
    };
    for(int i = 0; i < 100; i++) {
        if(arr[i] % 8 == 0 || arr[i] % 15 == 0) result[temp++] = arr[i];
    };
    for(int i = 0; i < temp; i++) {
        printf("%d ", result[i]);
    };
}