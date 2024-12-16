#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
} Node;

typedef Node* NodePtr;

typedef struct Polynomial {
    NodePtr head;
} Polynomial;


// Function to create a new polynomial
void initPolynomial(Polynomial* poly) {
    poly->head = NULL;
}

// Helper Function to check whether a term exists in the polynomial
int checkDuplicate(Polynomial* poly, int coeff, int exp) {
    NodePtr p;
    for (p = poly->head; p != NULL; p = p->next) {
        if (p->exponent == exp) {
            p->coefficient = coeff;
            return 1; 
        }
    }
    return 0;
}

void insertTerm(Polynomial* poly, int coeff, int exp) {
    NodePtr p = (NodePtr)malloc(sizeof(Node));
    NodePtr current = poly->head;

    // Avoid duplicate terms
    if (checkDuplicate(poly, coeff, exp)) {
        free(p);
        return;
    }

    p->coefficient = coeff;
    p->exponent = exp;
    p->next = NULL;

    // Case 1: List is empty
    if (!current) {
        poly->head = p;
        return;
    }

    // Case 2: Inserting at the beginning
    if (current->exponent < exp) {
        p->next = current;
        poly->head = p;
        return;
    }

    // Case 3: Insert somewhere in the middle or end
    while (current->next && current->next->exponent > exp) {
        current = current->next;
    }
    p->next = current->next;
    current->next = p;
}

// Function to perform polynomial addition
Polynomial addPolynomials(Polynomial* poly1, Polynomial* poly2) {
    Polynomial result;
    initPolynomial(&result);

    NodePtr p1 = poly1->head;
    NodePtr p2 = poly2->head;

    while (p1 != NULL || p2 != NULL) {
        if (!p1) {
            insertTerm(&result, p2->coefficient, p2->exponent);
            p2 = p2->next;
        } else if (!p2) {
            insertTerm(&result, p1->coefficient, p1->exponent);
            p1 = p1->next;
        } else if (p1->exponent > p2->exponent) {
            insertTerm(&result, p1->coefficient, p1->exponent);
            p1 = p1->next;
        } else if (p1->exponent < p2->exponent) {
            insertTerm(&result, p2->coefficient, p2->exponent);
            p2 = p2->next;
        } else {
            insertTerm(&result, p1->coefficient + p2->coefficient, p1->exponent);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return result;
}

// Function to perform polynomial subtraction
Polynomial subtractPolynomials(Polynomial* poly1, Polynomial* poly2) {
    Polynomial result;
    initPolynomial(&result);

    NodePtr p1 = poly1->head;
    NodePtr p2 = poly2->head;

    while (p1 != NULL || p2 != NULL) {
        if (!p1) {
            insertTerm(&result, -p2->coefficient, p2->exponent);
            p2 = p2->next;
        } else if (!p2) {
            insertTerm(&result, p1->coefficient, p1->exponent);
            p1 = p1->next;
        } else if (p1->exponent > p2->exponent) {
            insertTerm(&result, p1->coefficient, p1->exponent);
            p1 = p1->next;
        } else if (p1->exponent < p2->exponent) {
            insertTerm(&result, -p2->coefficient, p2->exponent);
            p2 = p2->next;
        } else {
            insertTerm(&result, p1->coefficient - p2->coefficient, p1->exponent);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return result;
}

// Function to perform polynomial multiplication
Polynomial multiplyPolynomials(Polynomial* poly1, Polynomial* poly2) {
    Polynomial result;
    initPolynomial(&result);

    for (NodePtr p1 = poly1->head; p1 != NULL; p1 = p1->next) {
        Polynomial temp;
        initPolynomial(&temp);
        for (NodePtr p2 = poly2->head; p2 != NULL; p2 = p2->next) {
            int newCoeff = p1->coefficient * p2->coefficient;
            int newExp = p1->exponent + p2->exponent;
            insertTerm(&temp, newCoeff, newExp);
        }
        result = addPolynomials(&result, &temp);
    }
    return result;
}

// Function to evaluate the polynomial for a given value of x
int evaluatePolynomial(Polynomial* poly, int x) {
    int result = 0;
    NodePtr current = poly->head;
    while (current) {
        result += current->coefficient * pow(x, current->exponent);
        current = current->next;
    }
    return result;
}

// Function to display the polynomial
void displayPolynomial(Polynomial* poly) {
    NodePtr current = poly->head;
    if (!current) {
        return;
    }

    while (current) {
        if (current->exponent != 0) {
            printf("%dx^%d", current->coefficient, current->exponent);
        } else {
            printf("%d", current->coefficient);
        }
        current = current->next;
        if (current && current->coefficient > 0) {
            printf(" + ");
        } else if (current && current->coefficient < 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    Polynomial poly1, poly2, result;
    initPolynomial(&poly1);
    initPolynomial(&poly2);

    insertTerm(&poly1, 3, 2);  // 3x^2
    insertTerm(&poly1, 4, 1);  // 4x^1
    insertTerm(&poly1, 5, 0);  // 5

    insertTerm(&poly2, 1, 2);  // x^2
    insertTerm(&poly2, 2, 1);  // 2x^1

    printf("Poly 1: ");
    displayPolynomial(&poly1);

    printf("Poly 2: ");
    displayPolynomial(&poly2);

    result = addPolynomials(&poly1, &poly2);
    printf("Addition: ");
    displayPolynomial(&result);

    result = subtractPolynomials(&poly1, &poly2);
    printf("Subtraction: ");
    displayPolynomial(&result);

    result = multiplyPolynomials(&poly1, &poly2);
    printf("Multiplicatin: ");
    displayPolynomial(&result);

    int x;
    printf("Enter the value of x for evaluation: ");
    scanf("%d", &x);
    int eval = evaluatePolynomial(&poly1, x);
    printf("Evaluation of Polynomial 1 at x=%d: %d\n", x, eval);

    return 0;
}
