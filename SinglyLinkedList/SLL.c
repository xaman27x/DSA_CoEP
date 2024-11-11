#include <stdio.h>
#include <stdlib.h>
#include "SLL.h"

void init(List *l) {
    *l = NULL;
    return;
}

void insertAtBeginning(List* l, int data) {
    node* temp = (node*) malloc(sizeof(node));
    if(!temp) return;

    temp->data = data;
    temp->next = *l;

    *l = temp;
    return;
}

void append(List* l, int data) {
    node* newNode = (node*) malloc(sizeof(node));
    if(!newNode) return;
    newNode->data = data;
    newNode->next = NULL;

    if (!*l) {
        *l = newNode;
        return;
    }

    node* p = *l;

    while(p->next) {
        p = p->next;
    };

    p->next = newNode;
    return;
}

void removeAtBeginning(List* l) {
    if(!*l) return;

    node* temp = *l;
    *l = (*l)->next;
    free(temp);

    return;
}

void removeAtEnd(List* l) {
    if(!*l) return;
    node* p, *q;

    if(!p->next) {
        *l = NULL;
        free(p);
        return;
    }

    while(p->next->next) {
        q = p;
        p = p->next;
    }
    q = p->next;
    p->next = NULL;
    free(q);
    return;
}

void display(List *l) {
    if(!*l) return;

    node* temp = *l;
    while(temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return;
}

int search(List *l, int data) {

    if(!*l) return -1;
    node* p = *l;
    int index = 0;
    while(p->next) {
        if(p->data == data) {
            return index;
            break;
        }
        index++;
        p = p->next;
    }
    return -1;
}

void destroy(List *l) {
    if(!*l) return;
    while(*l) {
        removeAtBeginning(l);
    }
    return;
}