
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int front, rear;
} QUEUE;

void initq(QUEUE *pq) {
    pq->front = pq->rear = -1;
}

void addq(QUEUE *pq, int num) {
    pq->rear++;
    pq->data[pq->rear] = num;
}

int removeq(QUEUE *pq) {
    int num;
    pq->front++;
    num = pq->data[pq->front];
    return(num);
}

int isempty(QUEUE *pq) {
    return(pq->front == pq->rear);
}

int isfull(QUEUE *pq) {
    return(pq->rear == MAX-1);
}

void bfs(int m[][10], int n) {
    int i, j, v, w;
    int visited[10] = {0};
    QUEUE q;
    initq(&q);
    printf("BFS Traversal Is: ");
    v = 0; 
    visited[0] = 1;
    addq(&q, v);
    while (!isempty(&q)) {
        v = removeq(&q);
        printf("v%d ", v+1);
        for (w = 0; w < n; w++) {
            if (m[v][w] == 1 && visited[w] == 0) {
                addq(&q, w);
                visited[w] = 1;
            }
        }
    }
}

int main() {
    int vertices, src, dest, edges, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    int m[vertices][vertices];
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            m[i][j] = 0;
        }
    }
    printf("How many edges: ");
    scanf("%d", &edges);
    for (i = 0; i < edges; i++) {
        printf("Enter edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        m[src-1][dest-1] = 1;
        m[dest-1][src-1] = 1;
    }
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    bfs(m,vertices);
    printf("\n");
    return 0;
}

