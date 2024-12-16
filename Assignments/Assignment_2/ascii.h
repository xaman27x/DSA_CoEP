typedef struct node {
    int digit;
    struct node* next;
    struct node* prev;
} node;

typedef struct ascii {
    node* front;
    node* rear;   
} ascii;

// Helper Functions
int isEmpty(ascii* l); 
void insertAtBeginning(ascii *l, int digit);
void removeAtBeginning(ascii* l);

// ASCII Prototypes
void init_ASCII(ascii** l);  
void ASCII_of(ascii* l, char c);
void traverse(ascii* l);
void destroy(ascii* l);
