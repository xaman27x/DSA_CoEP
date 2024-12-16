#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Stack {
    int *A;
    int size;
    int top;
} Stack;

void init(Stack *s, int size) {
    s->A = (int*) malloc(sizeof(int) * size);
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

void push(Stack *s, int element) {
    if(isFull(s)) return;
    s->A[++s->top] = element;
    return;
}

int pop(Stack* s) {
    if(isEmpty(s)) return INT_MIN;
    return s->A[s->top--];
}

int peek(Stack *s) {
    if(isEmpty(s)) return INT_MIN;
    return s->A[s->top];
}

void d2b(Stack* s, int value) {
    int rem;
    init(s, 32);
    while(value) {
        rem = value % 2;
        push(s, rem);
        value /= 2;
    }
    while(!isEmpty(s)) {
        printf("%d", pop(s));
    };
    return;
}

int main() {
    Stack* s;
    d2b(s, 24924);
    return 0;
}