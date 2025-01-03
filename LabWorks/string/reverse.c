#include <stdio.h>
#include <string.h>

void reverse(char string[]) {
    int len = strlen(string), temp;
    for(int i = 0; i < len / 2; i++) {
        temp = string[i];
        string[i] = string[len - i - 1];
        string[len - i - 1] = temp;
    }
    string[len] = '\0';
}

int main() {
    char p[100];

    printf("Enter a string: ");
    fgets(p, sizeof(p), stdin);

    p[strcspn(p, "\n")] = '\0'; 

    reverse(p);
    printf("Reversed string: %s\n", p);

    return 0;
}
