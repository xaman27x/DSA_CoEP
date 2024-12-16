#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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

int isValid(char c, char d) {
    return c == '(' && d == ')' || c == '[' && d == ']' || c == '{' && d == '}';  
}

int opening(char c) {
    return c == '(' || c == '[' || c == '{';
}

int closing(char c) {
    return c == ')' || c == ']' || c == '}';
}

int ValidParenthesis(char* array, Stack*s) {
    int len = strlen(array);
    init(s, len);
    for(int i = 0; i < len; i++) {
        if(opening(array[i])) {
            push(s, array[i]);
        } else if(closing(array[i])) {
            if(isValid(peek(s), array[i])) {
                pop(s);
            }
        } else {
            printf("INVALID CHAR");
            return -1;
        }
    }
    return isEmpty(s);
}

int main() {
    Stack *s;
    printf("%d\n", ValidParenthesis("[()]{}{[()()]()}", s));
    printf("%d\n", ValidParenthesis("[(])", s));
    return 0;
}