#include <stdio.h>
#include <string.h>

int digitCheck(char p) {
    if(p >= '0' && p <= '9') {
        return 1;
    }
    return -1;
}

int main() {
    char digits[100];  
    scanf("%s", digits);

    int len = strlen(digits);
    for(int i = 0; i < len; i++) {
        if(digitCheck(digits[i]) != 1) {
            printf("Non-digit character found: %c\n", digits[i]);
            return 0;
        }
    }
    for(int i = 0; i < len; i++) {
        printf("%c", digits[i]);
    }
    printf("\n");

    return 0;
}
