#include<stdio.h>
#include<stdlib.h>
#define max 20

struct stack {
    int a[max];
    int top;
};

typedef struct stack STACK;

void init(STACK *ps) {
    ps->top = -1;
}

void push(STACK *ps, int ele) {
    ps->a[++ps->top] = ele;
}

int pop(STACK *ps) {
    return ps->a[ps->top--];
}

int isempty(STACK *ps) {
    return ps->top == -1;
}

int isfull(STACK *ps) {
    return ps->top == max - 1;
}

void topologicalsort(int m[][10], int n) {
    STACK s;
    init(&s);
    int i, j, v, w;
    int visited[20] = {0};
    int indegree[10] = {0};
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            indegree[i] = indegree[i] + m[j][i];
        }
    }
    
    while (1) {
        for (v = 0; v < n; v++) {
            if ((visited[v] == 0) && (indegree[v] == 0)) {
                visited[v] = 1;
                push(&s, v);
                printf("v%d ", v + 1);
            }
        }

        if (isempty(&s)) {
            break;
        }

        v = pop(&s);
        
        for (w = 0; w < n; w++) {
            if (m[v][w] == 1) {
                indegree[w] = indegree[w] - 1;
            }
        }
    }
}

int main() {
    int m[10][10], vertices, i, j;
    printf("How Many Vertices: ");
    scanf("%d", &vertices);
    
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    
    topologicalsort(m, vertices);
    return 0;
}
