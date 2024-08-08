#include <stdio.h>

int main() {
    float salary;
    scanf("%f", &salary);
    if(salary <= 10000) {
        salary += 0.2 * salary + 0.8 * salary;
    } else if(salary <= 20000) {
        salary += 0.25 * salary + 0.9 * salary;
    } else {
        salary += 0.3 * salary + 0.95 * salary;
    };
    printf("%.3f", salary);
};