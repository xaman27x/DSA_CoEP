#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int*)malloc(capacity * sizeof(int));
    return stack;
}

bool isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int value) {
    if (stack->top < stack->capacity - 1) {
        stack->data[++stack->top] = value;
    }
}

int pop(Stack* stack) {
    if (!isStackEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return -1; 
}


bool isCyclic(int** graph, int V) {
    bool* visited = (bool*) calloc(V, sizeof(bool));
    bool* recStack = (bool*) calloc(V, sizeof(bool));

    Stack* stack = createStack(V);

    for (int src = 0; src < V; ++src) {
        if (!visited[src]) {
            push(stack, src);

            while (!isStackEmpty(stack)) {
                int u = pop(stack);

                if (!visited[u]) {
                    visited[u] = true;
                    recStack[u] = true;
                    push(stack, u);

                    for (int v = 0; v < V; v++) {
                        if (graph[u][v]) { // There's an edge from u to v
                            if (!visited[v]) {
                                push(stack, v);
                            } else if (recStack[v]) {
                                // If v is in the recursion stack, cycle detected
                                free(visited);
                                free(recStack);
                                free(stack);
                                return true;
                            }
                        }
                    }
                } else {
                    recStack[u] = false;
                }
            }
        }
    }

    free(visited);
    free(recStack);
    free(stack);
    return false;
}



int** createAdjMatrix(int V) {
    int** adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        adj[i] = (int*)calloc(V, sizeof(int));
    }
    return adj;
}

void addEdge(int** adj, int src, int dest) {
    adj[src][dest] = 1;
}

int main() {
    int V = 4; 
    int** adj = createAdjMatrix(V);

    // Adding random edges
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);

    if (isCyclic(adj, V)) {
        printf("Cycle Detected\n");
    } else {
        printf("Cycle not Detected\n");
    }
    for (int i = 0; i < V; i++) {
        free(adj[i]);
    }
    free(adj);

    return 0;
}
