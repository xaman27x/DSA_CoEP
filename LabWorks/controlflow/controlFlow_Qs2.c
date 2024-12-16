#include <stdio.h>

int main() {
    float a, b;
    scanf("%f %f", &a, &b);
    int result = a + b;
    printf("%f %f %d", a, b, result);
    return 0;
}