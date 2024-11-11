#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cutonchar(const char* str, char ch) {
    const char* temp = str;
    const char* closest_whitespace = NULL;
    char* finalstr = NULL;
    int len = 0;

    while (*temp != '\0') {
        if (*temp == ch) {
            if (closest_whitespace == NULL) {
                closest_whitespace = str;
            }
            len = closest_whitespace - str;
            finalstr = (char*)malloc((len + 1) * sizeof(char));
            if (finalstr == NULL) {
                return NULL; 
            }
            strncpy(finalstr, str, len);
            
            finalstr[len] = '\0';
            break;
        } else if (*temp == ' ') {
            closest_whitespace = temp + 1; 
        }
        temp++;
    }

    return finalstr;
}

int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    
    char* string = cutonchar(str, 'm');
    if (string != NULL) {
        printf("%s\n", string);
        free(string); 
    } else {
        printf("Memory allocation failed or character not found.\n");
    }
    return 0;
}
