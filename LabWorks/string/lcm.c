#include <stdio.h>

int find_lcm(int num1, int num2) {
    int temp1 = 2, temp2 = 2, flag = 1, result1 = num1, result2 = num2;
    while(flag) {
        if(result1 != result2) {
            if(result1 < result2) {
                result1 = num1*temp1;
                temp1++;
            } else {
                result2 = num2*temp2;
                temp2++;
            };
        } else {
            flag = 0;
            break;
        };
    };
    return result1;
};

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    int lcm = find_lcm(x, y);
    printf("%d", lcm);
    return 0;
}