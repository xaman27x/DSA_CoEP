#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Stack {
    char* A;
    int size;
    int top;
} Stack;

void init(Stack* s, int size) {
    s->A = (char*) malloc(sizeof(char) * size);
    if (!s->A) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    s->top = -1;
    s->size = size;
}

void push(Stack* s, char value) {
    if (s->top == s->size - 1) {
        printf("Stack overflow!\n");
    } else {
        s->A[++(s->top)] = value;
    }
}

char pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack underflow!\n");
        return '\0';
    } else {
        return s->A[(s->top)--];
    }
}

char peek(Stack* s) {
    if (s->top == -1) {
        return '\0';
    } else {
        return s->A[s->top];
    }
}

void freeStack(Stack* s) {
    free(s->A);
}

int precedence(char c) {
    switch (c) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return -1;
    }
}

int checkIfOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void infixToPostfix(char* infix) {
    Stack s;
    init(&s, MAX);
    
    int i = 0, j = 0;
    int len = strlen(infix); 
    char postfix[MAX];    

    while (infix[i] != '\0') {

        if (checkIfOperand(infix[i])) {
            postfix[j++] = infix[i];
        }

        else if (infix[i] == '(') {
            push(&s, infix[i]);
        }
        else if (infix[i] == ')') {
            while (s.top != -1 && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        }

        else {
            while (s.top != -1 && precedence(peek(&s)) >= precedence(infix[i])) {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
        i++;
    }
    while (s.top != -1) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0'; 

    printf("%s\n", postfix);
    freeStack(&s);
}

int main() {
    char infix[MAX];
    scanf("%s", infix);
    infixToPostfix(infix);

    return 0;
}
