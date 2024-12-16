#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *tail = NULL;

void init() {
    int i, x;
    printf("How Many Elements You want to add: ");
    scanf("%d", &x);
    for (i = 1; i <= x; i++) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d of the linked list: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (!tail) {
            tail = newNode;
            tail->next = newNode;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }
    return;
}

void insertAtBeg() {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data you want to insert: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (!tail) {
        tail = newNode;
        tail->next = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
    return;
}

void insertAtEnd() {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data you want to insert: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (!tail) {
        tail = newNode;
        tail->next = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    return;
}

void delAtBeg() {
    if (!tail) return;
    struct Node *temp = tail->next;
    if (tail == tail->next) {
        free(tail);
        tail = NULL;
    } else {
        tail->next = temp->next;
        free(temp);
    }
    return;
}

void delAtEnd() {
    if (!tail) return;
    struct Node *current = tail->next;
    if (tail == tail->next) {
        free(tail);
        tail = NULL;
    } else {
        while (current->next != tail) {
            current = current->next;
        }
        current->next = tail->next;
        free(tail);
        tail = current;
    }
    return;
}

void display() {
    if (!tail) {
        printf("Linked List is Empty\n");
        return;
    }
    struct Node *temp = tail->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
    return;
}

void search() {
    if (!tail) {
        printf("Linked List is Empty\n");
        return;
    }
    int key, pos = 1;
    printf("Enter the value to search: ");
    scanf("%d", &key);
    struct Node *temp = tail->next;
    do {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != tail->next);
    printf("Element %d not found in the list.\n", key);
    return;
}

void sort() {
    if (!tail || tail->next == tail) return;
    struct Node *i, *j;
    int temp;
    for (i = tail->next; i->next != tail->next; i = i->next) {
        for (j = i->next; j != tail->next; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return;
}

int main() {
    int opt;
    while (1) {
        printf("\nWhich operation do you want to perform?\n");
        printf("1. Initialize a Linked List\n");
        printf("2. Display\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Search\n");
        printf("8. Sort\n");
        printf("9. Exit\n");
        scanf("%d", &opt);

        switch (opt) {
        case 1:
            init();
            break;
        case 2:
            display();
            break;
        case 3:
            insertAtBeg();
            break;
        case 4:
            insertAtEnd();
            break;
        case 5:
            delAtBeg();
            break;
        case 6:
            delAtEnd();
            break;
        case 7:
            search();
            break;
        case 8:
            sort();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}
