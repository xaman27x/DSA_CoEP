#include <stdio.h>
#include <stdbool.h>

char* my_strtok(char* str, const char* delimiter) {
    static char* nextToken = NULL;
    
    if (str != NULL) {
        nextToken = str;
    }

    if (nextToken == NULL) {
        return NULL;
    }

    char* start = nextToken;
    while (*start && strchr(delimiter, *start)) {
        start++;
    }

    if (*start == '\0') {
        nextToken = NULL;
        return NULL;
    }

    char* end = start;
    while (*end && !strchr(delimiter, *end)) {
        end++;
    }

    if (*end) {
        *end = '\0';
        nextToken = end + 1;
    } else {
        nextToken = NULL;
    }

    return start;
}
