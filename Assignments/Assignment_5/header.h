#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enumeration for Months
typedef enum {
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
} Month;

// BST Node Structure
typedef struct BSTNode {
    Month month;
    struct BSTNode *left;
    struct BSTNode *right;
    struct BSTNode *parent;
} BSTNode;

void initBST(BSTNode **root);
BSTNode* createNode(Month month);
void insertNode(BSTNode **root, const char *monthName); 
BSTNode* findNode(BSTNode *root, Month month);
void removeNode(BSTNode **root, const char *monthName); 
void removeNodeByEnum(BSTNode **root, Month month);  // Helper function
void traverse(BSTNode *root);
void destroyTree(BSTNode *root);
void displayMenu();
Month monthStringToEnum(const char *monthName);

#endif
