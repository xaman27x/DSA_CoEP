#include <stdio.h>
#include <stdlib.h>
#include "SLL.c"

int main() {
    List l;
    init(&l);
    insertAtBeginning(&l, 5);
    insertAtBeginning(&l, 10);
    append(&l, 11);
    printf("%d\n", search(&l, 13));
    display(&l);
    destroy(&l);
    display(&l);
    return 0;
}