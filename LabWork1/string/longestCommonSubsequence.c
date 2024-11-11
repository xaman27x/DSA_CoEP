#include <stdio.h>
#include <string.h>

typedef struct {
    int length;
    char *ptr;
} Result;

Result longestSubsequence(char *str1, char *str2) {
    Result res;
    res.length = 0;
    res.ptr = NULL;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            int k = 0;
            while (i + k < len1 && j + k < len2 && str1[i + k] == str2[j + k]) {
                k++;
            }

            if (k > res.length) {
                res.length = k;
                res.ptr = &str1[i];
            }
        }
    }
    return res;
}

int main() {
    char str1[] = "abcdemnopxyz";
    char str2[] = "mnotq";
    Result res = longestSubsequence(str1, str2);
    printf("Length: %d, Subseq: %.*s\n", res.length, res.length, res.ptr);
    return 0;
}
