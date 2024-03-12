#include <stdio.h>
#include <stdlib.h>

void dfs(int m[10][10], int n, int v) {
    int visited[n], w;
    for (w = 0; w < n; w++)
        visited[w] = 0;
    visited[v] = 1;
    printf("v%d\t", v+1);
    for (w = 0; w < n; w++) {
        if (m[v][w] == 1 && visited[w] == 0) {
            dfs(m, n, w);
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
        scanf("%d%d", &src, &dest);
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
    printf("\nDFS Traversal: ");
    dfs(m, vertices, 0);
    return 0;
}
