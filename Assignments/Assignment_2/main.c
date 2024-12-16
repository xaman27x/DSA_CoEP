#include <stdio.h>
#include "ascii.c"

int main() {
    ascii *l;
    init_ASCII(&l);
    ASCII_of(l, 'a');
    traverse(l);
    destroy(l);
    traverse(l);
    return 0;
}
