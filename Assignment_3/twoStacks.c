#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct twoStacks {
    int* A;
    int* B;
    int sizeA;
    int sizeB;
    int topA;
    int topB;
} twoStacks;



void init(twoStacks** s) {
    *s = (twoStacks*) malloc(sizeof(twoStacks));
    (*s)->A = (int*) malloc(2 * sizeof(int));
    if(!(*s)->A) return;
    (*s)->sizeA = 1;
    (*s)->sizeB = 1;
    (*s)->B = (int*) malloc(2 * sizeof(int)); 
    (*s)->topA = 0;
    (*s)->topB = 0;
}

void push1(twoStacks* s, int x) {
    s->sizeA++;
    s->A = realloc(s->A, s->sizeA * sizeof(int));
    s->A[s->topA++] = x;
}

int pop1(twoStacks* s) {
    if (s->topA == 0) {;
        return INT_MIN; 
    }
    return s->A[--s->topA];
}

void push2(twoStacks* s, int x) {
    s->sizeB++;
    s->B = realloc(s->B, s->sizeB * sizeof(int));
    s->B[s->topB++] = x;
}

int pop2(twoStacks* s) {
    if (s->topB == 0) {
        return INT_MIN; 
    }
    return s->B[--s->topB];
}

void freeStacks(twoStacks* s) {
    free(s->A);
    free(s->B);
    free(s);
}

int main() {
    twoStacks *s;
    init(&s);
    push1(s, 5);
    push2(s, 10);
    printf("%d\n", pop1(s));
    printf("%d\n", pop2(s));
    freeStacks(s);
    return 0;
}
