/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define MAXN 50005
#define LOG 17

int head[MAXN], to[2 * MAXN], nxt[2 * MAXN], ec;
int parent[MAXN], depth[MAXN];
int tin[MAXN], tout[MAXN], timer;
int up[LOG][MAXN];
int bit[MAXN + 5];

void addEdge(int u, int v) {
    to[ec] = v;
    nxt[ec] = head[u];
    head[u] = ec++;
}

void bitUpdate(int i, int val, int n) {
    while (i <= n + 1) {
        bit[i] ^= val;
        i += i & -i;
    }
}

int bitQuery(int i) {
    int ans = 0;

    while (i > 0) {
        ans ^= bit[i];
        i -= i & -i;
    }

    return ans;
}

void rangeUpdate(int l, int r, int val, int n) {
    bitUpdate(l + 1, val, n);
    bitUpdate(r + 2, val, n);
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        int t = u;
        u = v;
        v = t;
    }

    int diff = depth[u] - depth[v];

    for (int j = 0; j < LOG; j++) {
        if (diff & (1 << j))
            u = up[j][u];
    }

    if (u == v)
        return u;

    for (int j = LOG - 1; j >= 0; j--) {
        if (up[j][u] != up[j][v]) {
            u = up[j][u];
            v = up[j][v];
        }
    }

    return parent[u];
}

bool* palindromePath(int n, int** edges, int edgesSize,
                     int* edgesColSize, char* s,
                     char** queries, int queriesSize,
                     int* returnSize) {

    ec = 0;
    timer = 0;
    memset(bit, 0, sizeof(bit));

    for (int i = 0; i < n; i++)
        head[i] = -1;

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        addEdge(u, v);
        addEdge(v, u);
    }

    // Iterative DFS: calculate parent, depth, tin and tout.
    int *st = malloc(n * sizeof(int));
    int *it = malloc(n * sizeof(int));

    int top = 0;
    st[0] = 0;
    it[0] = head[0];
    parent[0] = 0;
    depth[0] = 0;
    tin[0] = timer++;

    while (top >= 0) {
        int u = st[top];
        int e = it[top];

        if (e == -1) {
            tout[u] = timer - 1;
            top--;
            continue;
        }

        it[top] = nxt[e];
        int v = to[e];

        if (v == parent[u])
            continue;

        parent[v] = u;
        depth[v] = depth[u] + 1;
        tin[v] = timer++;

        top++;
        st[top] = v;
        it[top] = head[v];
    }

    free(st);
    free(it);

    // Build the binary lifting table for LCA.
    for (int i = 0; i < n; i++)
        up[0][i] = parent[i];

    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i < n; i++)
            up[j][i] = up[j - 1][up[j - 1][i]];
    }

    // Build root-to-node character masks.
    for (int i = 0; i < n; i++) {
        int mask = 1 << (s[i] - 'a');
        rangeUpdate(tin[i], tout[i], mask, n);
    }

    bool *answer = malloc(queriesSize * sizeof(bool));
    int count = 0;

    for (int i = 0; i < queriesSize; i++) {
        char op[10];
        int u, v;

        sscanf(queries[i], "%9s", op);

        if (strcmp(op, "update") == 0) {
            char c;
            sscanf(queries[i], "%*s %d %c", &u, &c);

            int oldMask = 1 << (s[u] - 'a');
            int newMask = 1 << (c - 'a');

            if (oldMask != newMask) {
                rangeUpdate(tin[u], tout[u],
                            oldMask ^ newMask, n);
                s[u] = c;
            }
        } else {
            sscanf(queries[i], "%*s %d %d", &u, &v);

            int w = lca(u, v);

            int maskU = bitQuery(tin[u] + 1);
            int maskV = bitQuery(tin[v] + 1);
            int maskW = 1 << (s[w] - 'a');

            int mask = maskU ^ maskV ^ maskW;

            answer[count++] = (mask & (mask - 1)) == 0;
        }
    }

    *returnSize = count;
    return answer;
}
