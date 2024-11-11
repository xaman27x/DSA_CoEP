#include <stdio.h>

typedef struct node {
    int data;
    struct node* next;
} node;

typedef node* List;

void init(List *l);
void insertAtBeginning(List* l, int data);
void removeAtBeginning(List* l);
void append(List* l, int data);
void removeAtEnd(List* l);
void display(List *l);
int search(List* l, int data);
void destroy(List *l);

