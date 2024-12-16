#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node *next;
};

// Stack structure
struct Stack {
    struct Node *top;
};

// Initialize the stack
void initStack(struct Stack *s) {
    s->top = NULL;
}

// Push operation
void push(struct Stack *s) {
    int x;
    printf("Enter the Element to push: ");
    scanf("%d", &x);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = x;
    newNode->next = s->top;
    s->top = newNode;
    printf("%d pushed to Stack\n", x);
}

// Pop operation
void pop(struct Stack *s) {
    if (s->top == NULL) {
        printf("Stack underflow\n");
    } else {
        struct Node *temp = s->top;
        printf("Popped: %d\n", temp->data);
        s->top = s->top->next;
        free(temp);
    }
}

// Peek operation
void peek(struct Stack *s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top Element: %d\n", s->top->data);
    }
}

// Display the stack
void display(struct Stack *s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Displaying Stack....\n");
        struct Node *temp = s->top;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Stack s;
    initStack(&s);

    int ch;

    while (1) {
        printf("\n*** Stack Menu ***\n");
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Peek\n5. Exit\n");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                push(&s);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                peek(&s);
                break;
            case 5:
                exit(0);
            default:
                printf("\nWrong Choice!!\n");
        }
    }

    return 0;
}
