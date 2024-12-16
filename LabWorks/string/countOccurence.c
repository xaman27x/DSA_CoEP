#include <stdio.h>
#include <string.h>

int countOccurencesofChar(char str[], char ch) {
    int len = strlen(str), count = 0;
    for(int i = 0; i < len; i++) {
        if(str[i] == ch) count++;
    };
    return count;
};

int main() {
    char str[100];
    char ch;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    str[strcspn(str, "\n")] = '\0';

    printf("Enter a character to count: ");
    scanf("%c", &ch);
    
    int count = countOccurencesofChar(str, ch);
    printf("The character '%c' occurs %d times in the string \"%s\".\n", ch, count, str);
    
    return 0;
}

