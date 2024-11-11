#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    char *A;
    int size;
    int top;
} Stack;


void init(Stack *s, int size) {
    s->A = (char*) malloc(sizeof(char) * size);
    s->size = size;
    s->top = -1;
    return;
};

int isFull(Stack* s) {
    return s->top == s->size - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char element) {
    if(isFull(s)) return;
    s->A[++s->top] = element;
    return;
}

char pop(Stack* s) {
    if(isEmpty(s)) return CHAR_MIN;
    return s->A[s->top--];
}

char peek(Stack *s) {
    if(isEmpty(s)) return CHAR_MIN;
    return s->A[s->top];
}

void reverse(Stack *s , char *array) {
    int len = strlen(array);
    init(s, len);
    for(int i = 0; i < len; i++) {
        push(s, array[i]);
    };
    while(!isEmpty(s)) {
        printf("%c", pop(s));
    };
}

int main() {
    Stack* s;
    reverse(s, "Data Structures");
    return 0;
}