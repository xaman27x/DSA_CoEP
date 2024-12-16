#include <stdio.h>
#include <string.h>

int gcd(int num1, int num2) {
    int temp;
    if(num1 <= num2) {
        temp = num1;
    } else {
        temp = num2;
    };

    for(int i = temp; i >=1; i--) {
        if(num1 % i == 0 && num2 % i == 0) {
            return i;
        };
    };
    return 1;
}
// Time Complexity: O(n)
// Space complexity: O(1)

int main() {
    int z, y;
    scanf("%d %d", &z, &y);
    int x = gcd(z, y);
    printf("%d", x);
    return 0;
}