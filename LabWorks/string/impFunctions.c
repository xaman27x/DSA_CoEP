#include <stdio.h>
#include <ctype.h>
#include <string.h>

int my_strcasecmp(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        int diff = tolower(*s1) - tolower(*s2);
        if (diff != 0) {
            return diff;
        }
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

char *my_strsep(char *str, const char *delim) {
    char *token = str;
    if (str == NULL) {
        return NULL;
    }
    if (*str == '\0') {
        return NULL;
    }
    while (*str && strchr(delim, *str) == NULL) {
        str++;
    }
    if (*str) {
        *str++ = '\0';
        while (*str && strchr(delim, *str)) {
            str++;
        }
    }
    return token;
}

int my_strcoll(const char *s1, const char *s2) {
    return strcmp(s1, s2);
}
