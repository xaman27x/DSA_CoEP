#include "header.h"

int main() {
    BSTNode *root;
    initBST(&root);
    int choice;
    char monthName[20];

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%s", monthName);
                insertNode(&root, monthName);
                break;

            case 2:
                scanf("%s", monthName);
                removeNode(&root, monthName);
                break;

            case 3:
                traverse(root);
                break;

            case 4:
                root = NULL;
                printf("Tree destroyed.\n");
                break;

            case 5:
                destroyTree(root);
                return 0;

            default:
                printf("");;
        }
    }
}
