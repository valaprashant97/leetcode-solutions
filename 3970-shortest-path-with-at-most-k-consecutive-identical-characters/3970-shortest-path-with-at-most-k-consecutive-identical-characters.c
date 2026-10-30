
#include <stdlib.h>
#include <limits.h>

typedef long long ll;

typedef struct {
    ll d;
    int node, cnt;
} State;

State heap[1];
State *pq = NULL;
int sz = 0, cap = 0;

void push(State x) {
    if (sz == cap) {
        cap = cap ? cap * 2 : 1000;
        pq = realloc(pq, cap * sizeof(State));
    }

    int i = sz++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (pq[p].d <= x.d) break;
        pq[i] = pq[p];
        i = p;
    }
    pq[i] = x;
}

State pop() {
    State ans = pq[0];
    State x = pq[--sz];

    int i = 0;
    while (2 * i + 1 < sz) {
        int c = 2 * i + 1;

        if (c + 1 < sz && pq[c + 1].d < pq[c].d)
            c++;

        if (pq[c].d >= x.d) break;

        pq[i] = pq[c];
        i = c;
    }

    pq[i] = x;
    return ans;
}

long long shortestPath(int n, int** edges, int edgesSize,
                       int* edgesColSize, char* labels, int k) {

    int *head = malloc(n * sizeof(int));
    int *to = malloc(edgesSize * sizeof(int));
    int *weight = malloc(edgesSize * sizeof(int));
    int *next = malloc(edgesSize * sizeof(int));

    for (int i = 0; i < n; i++)
        head[i] = -1;

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        to[i] = v;
        weight[i] = edges[i][2];
        next[i] = head[u];
        head[u] = i;
    }

    int cols = k + 1;
    int total = n * cols;

    ll *dist = malloc((size_t)total * sizeof(ll));

    for (int i = 0; i < total; i++)
        dist[i] = LLONG_MAX;

    sz = 0;
    cap = 0;
    free(pq);
    pq = NULL;

    dist[1] = 0;
    push((State){0, 0, 1});

    while (sz > 0) {
        State cur = pop();

        int u = cur.node;
        int cnt = cur.cnt;
        ll d = cur.d;

        int id = u * cols + cnt;

        if (d != dist[id])
            continue;

        if (u == n - 1) {
            free(head);
            free(to);
            free(weight);
            free(next);
            free(dist);
            free(pq);
            pq = NULL;
            return d;
        }

        for (int e = head[u]; e != -1; e = next[e]) {
            int v = to[e];

            int newCnt;

            if (labels[u] == labels[v])
                newCnt = cnt + 1;
            else
                newCnt = 1;

            if (newCnt > k)
                continue;

            ll nd = d + weight[e];
            int newId = v * cols + newCnt;

            if (nd < dist[newId]) {
                dist[newId] = nd;
                push((State){nd, v, newCnt});
            }
        }
    }

    free(head);
    free(to);
    free(weight);
    free(next);
    free(dist);
    free(pq);
    pq = NULL;

    return -1;
}
