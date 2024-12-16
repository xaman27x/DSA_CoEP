#include <stdio.h>
#include <stdlib.h>
#include "poly.c"

int main() {
    poly* p, *p2, *p3;
    p = (poly*) malloc(sizeof(p));
    p2 = (poly*) malloc(sizeof(p));
    p3 = (poly*) malloc(sizeof(p));
    init_poly(p, 3);
    init_poly(p2, 3);
    init_poly(p3, 3);
    append(p, 4, 2);
    append(p, 7, 1);
    append(p, 3, 0);
    append(p2, 2, 2);
    append(p2, 7, 1);
    add_poly(p, p2, p3);
    sub_poly(p, p2, p3);
    printf("\n");
    quadratic_roots(p);
    return 0;
}