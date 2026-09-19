#include <stdlib.h>

int timer = 0;

void dfs(int u, int parent, int **graph, int *degree,
         int *disc, int *low, int **ans,
         int *count, int *colSize) {
    
    disc[u] = low[u] = timer++;

    for (int i = 0; i < degree[u]; i++) {
        int v = graph[u][i];

        if (v == parent)
            continue;

        if (disc[v] == -1) {
            dfs(v, u, graph, degree, disc, low,
                ans, count, colSize);

            if (low[v] < low[u])
                low[u] = low[v];

            if (low[v] > disc[u]) {
                ans[*count] = malloc(2 * sizeof(int));
                ans[*count][0] = u;
                ans[*count][1] = v;
                colSize[*count] = 2;
                (*count)++;
            }
        } else {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** criticalConnections(int n, int** connections, int connectionsSize,
                          int* connectionsColSize, int* returnSize,
                          int** returnColumnSizes) {

    int **graph = malloc(n * sizeof(int *));
    int *degree = calloc(n, sizeof(int));
    int *pos = calloc(n, sizeof(int));

    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];

        degree[u]++;
        degree[v]++;
    }

    for (int i = 0; i < n; i++)
        graph[i] = malloc(degree[i] * sizeof(int));

    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];

        graph[u][pos[u]++] = v;
        graph[v][pos[v]++] = u;
    }

    int *disc = malloc(n * sizeof(int));
    int *low = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        disc[i] = -1;

    int **ans = malloc((n - 1) * sizeof(int *));
    *returnColumnSizes = malloc((n - 1) * sizeof(int));

    *returnSize = 0;
    timer = 0;

    for (int i = 0; i < n; i++) {
        if (disc[i] == -1) {
            dfs(i, -1, graph, degree, disc, low,
                ans, returnSize, *returnColumnSizes);
        }
    }

    for (int i = 0; i < n; i++)
        free(graph[i]);

    free(graph);
    free(degree);
    free(pos);
    free(disc);
    free(low);

    return ans;
}