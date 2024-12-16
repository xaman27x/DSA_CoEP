#include <stdio.h>
#include <stdlib.h>

#define N 50

// Stack structure definition
struct Stack {
    int data[N];
    int top;
};

// Initialize the stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Push operation
void push(struct Stack *s) {
    int x;
    printf("Enter the Element to push: ");
    scanf("%d", &x);

    if (s->top == N - 1) {
        printf("Stack overflow\n");
    } else {
        s->top++;
        s->data[s->top] = x;
        printf("%d pushed to Stack\n", x);
    }
}

// Pop operation
void pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
    } else {
        int item = s->data[s->top];
        s->top--;
        printf("Popped: %d\n", item);
    }
}

// Peek operation
void peek(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top Element: %d\n", s->data[s->top]);
    }
}

// Display the stack
void display(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Displaying Stack....\n");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->data[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack s;
    initStack(&s);

    int ch;

    while (1) {
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
