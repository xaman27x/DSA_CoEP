#include "header.h"

void initBST(BSTNode **root) {
    *root = NULL;
    return;
}

// Convert month string to enum value
Month monthStringToEnum(const char *monthName) {
    if (strcasecmp(monthName, "January") == 0) return JANUARY;
    if (strcasecmp(monthName, "February") == 0) return FEBRUARY;
    if (strcasecmp(monthName, "March") == 0) return MARCH;
    if (strcasecmp(monthName, "April") == 0) return APRIL;
    if (strcasecmp(monthName, "May") == 0) return MAY;
    if (strcasecmp(monthName, "June") == 0) return JUNE;
    if (strcasecmp(monthName, "July") == 0) return JULY;
    if (strcasecmp(monthName, "August") == 0) return AUGUST;
    if (strcasecmp(monthName, "September") == 0) return SEPTEMBER;
    if (strcasecmp(monthName, "October") == 0) return OCTOBER;
    if (strcasecmp(monthName, "November") == 0) return NOVEMBER;
    if (strcasecmp(monthName, "December") == 0) return DECEMBER;
    return 0; // Invalid month
}

BSTNode* createNode(Month month) {
    BSTNode *newNode = (BSTNode*)malloc(sizeof(BSTNode));
    newNode->month = month;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

BSTNode* findNode(BSTNode *root, Month month) {
    while (root != NULL) {
        if (month < root->month) {
            root = root->left;
        } else if (month > root->month) {
            root = root->right;
        } else {
            return root;
        }
    }
    return NULL;
}

void insertNode(BSTNode **root, const char *monthName) {
    Month month = monthStringToEnum(monthName);
    if (month == 0) {
        printf("Invalid month name: %s\n", monthName);
        return;
    }

    BSTNode *newNode = createNode(month);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    BSTNode *current = *root;
    BSTNode *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (month < current->month)
            current = current->left;
        else if (month > current->month)
            current = current->right;
        else
            return; // Duplicate month
    }

    newNode->parent = parent;
    if (month < parent->month)
        parent->left = newNode;
    else
        parent->right = newNode;
}

// Main remove function (uses string input)
void removeNode(BSTNode **root, const char *monthName) {
    Month month = monthStringToEnum(monthName);
    if (month == 0) {
        return;
    }
    removeNodeByEnum(root, month);
}

// Helper function
void removeNodeByEnum(BSTNode **root, Month month) {
    BSTNode *nodeToDelete = findNode(*root, month);
    if (!nodeToDelete) return;

    BSTNode *child, *parent;

    if (!nodeToDelete->left || !nodeToDelete->right) {
        child = (nodeToDelete->left) ? nodeToDelete->left : nodeToDelete->right;
        parent = nodeToDelete->parent;
        if (parent == NULL)
            *root = child;
        else if (parent->left == nodeToDelete)
            parent->left = child;
        else
            parent->right = child;
        if (child)
            child->parent = parent;
        free(nodeToDelete);
    } else {
        BSTNode *successor = nodeToDelete->right;
        while (successor->left)
            successor = successor->left;
        nodeToDelete->month = successor->month;
        removeNodeByEnum(&nodeToDelete->right, successor->month);
    }
}

// In-order Traversal (Non-Recursive)
void traverse(BSTNode *root) {
    BSTNode *stack[100];
    int top = -1;
    BSTNode *current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->month);
        current = current->right;
    }
    printf("\n");
}

// Destroy the BST
void destroyTree(BSTNode *root) {
    if (root == NULL) return;
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}

// Display the menu options
void displayMenu() {
    printf("1. Insert\n");
    printf("2. Remove\n");
    printf("3. Traverse\n");
    printf("4. Destroy\n");
    printf("5. Exit\n");

}
