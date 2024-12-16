#include <stdio.h>

int main() {
    unsigned long int a;
    scanf("%d", &a);
    int check = a % 55 == 0 ? 1 : 0;
    if(check) {
        printf("Divisible\n");
    } else {
        printf("Not Divisible\n");
    };
    return 0;
};