typedef struct term {
    int coeff;
    int exp;
} term;

typedef struct polynomial {
    int n;
    struct term* t;
} poly;

void init_poly(poly* p, int size);
void append(poly* p, int coeff, int exp);
void display(poly* p);
void add_poly(poly* p1, poly* p2, poly* p3);
void sub_poly(poly* p1, poly* p2, poly* p3);
void quadratic_roots(poly* p);