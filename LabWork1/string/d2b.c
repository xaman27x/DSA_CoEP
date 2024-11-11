#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 64

void reverse(char string[]) {
    int len = strlen(string), temp;
    for (int i = 0; i < len / 2; i++) {
        temp = string[i];
        string[i] = string[len - i - 1];
        string[len - i - 1] = temp;
    }
}

char* d2b(int num) {
    char str[MAX_SIZE];
    int len = 0;
    if (num == 0) {
        str[len++] = '0';
    } else {
        while (num) {
            str[len++] = (num % 2) + '0'; 
            num /= 2;
        }
    }
    str[len] = '\0'; 
    reverse(str);

    char* final = (char*)malloc(len + 1); 
    if (final != NULL) {
        strcpy(final, str);
    }

    return final;
}

int main() {
    int x;
    scanf("%d", &x);
    char* binaryString = d2b(x);
    printf("%s\n", binaryString);
    free(binaryString); 
    return 0;
}
