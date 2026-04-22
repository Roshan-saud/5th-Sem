#include <stdio.h>

struct Edge {
    int u, v, w;
};

int parent[100];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int u, int v) {
    parent[u] = v;
}

void sort(struct Edge e[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (e[j].w > e[j+1].w) {
                struct Edge temp = e[j];
                e[j] = e[j+1];
                e[j+1] = temp;
            }
        }
    }
}

int main() {
    int v, e;

    // Example Input:
    // vertices = 4
    // edges = 5
    // u v w:
    // 0 1 10
    // 0 2 6
    // 0 3 5
    // 1 3 15
    // 2 3 4

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &v, &e);

    struct Edge edge[e];

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);

    for (int i = 0; i < v; i++)
        parent[i] = i;

    sort(edge, e);

    int total = 0;

    printf("Edges in MST:\n");
    for (int i = 0; i < e; i++) {
        int u = find(edge[i].u);
        int vtx = find(edge[i].v);

        if (u != vtx) {
            printf("%d - %d = %d\n", edge[i].u, edge[i].v, edge[i].w);
            total += edge[i].w;
            unionSet(u, vtx);
        }
    }

    printf("Total cost = %d\n", total);

    return 0;
}