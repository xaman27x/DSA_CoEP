#include <stdio.h>

typedef struct fraction {
    float numerator;
    float denominator;
} fraction;

int compareFractions(float num1, float num2) {
    if(num1 == num2) {
        return 0;
    } else if(num1 < num2) {
        return -1;
    } else {
        return 1;
    }
};

int main() {
    struct fraction f1, f2;
    printf("First Fraction (Numerator Denominator): ");
    scanf("%d %d", &f1.numerator, &f1.denominator);
    printf("Second Fraction (Numerator Denominator): ");
    scanf("%d %d", &f2.numerator, &f2.denominator);
    if(f1.denominator == 0 || f2.denominator == 0) {
        printf("Invalid");
        return 0;
    };
    
    int result = compareFractions(f1.numerator / f1.denominator, f2.numerator / f2.denominator);
    printf("%d", result);
    return 0;
}