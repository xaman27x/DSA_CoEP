typedef struct data {
    char name[16];
    unsigned int age;
} data;

typedef struct node {
    data info;
    struct node* next;
} node;

typedef struct queue {
    node* head;
    node* tail;
} queue;

// Function prototypes
void qinit(queue* q);
int qfull(queue* q);
int qempty(queue* q);
void enq(queue* q, data d);
data deq(queue* q);
