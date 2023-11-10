#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Compare function for sorting edges by weight
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Function to find the parent of a subset using path compression
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two subsets based on rank
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void findMinimumSpanningTree(struct Edge edges[], int V, int E) {
    struct Edge result[V];
    qsort(edges, E, sizeof(struct Edge), compareEdges);

    struct Subset subsets[V];
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int mstWeight = 0;
    int mstEdges = 0;
    for (int i = 0; mstEdges < V - 1 && i < E; i++) {
        struct Edge nextEdge = edges[i];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[mstEdges++] = nextEdge;
            unionSets(subsets, x, y);
            mstWeight += nextEdge.weight;
        }
    }

    printf("Edges in the minimum spanning tree:\n");
    for (int i = 0; i < mstEdges; i++) {
        printf("%d -- %d (Weight: %d)\n", result[i].src, result[i].dest, result[i].weight);
    }
    printf("Total weight of the minimum spanning tree: %d\n", mstWeight);
}

int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges

    // Create an array of edges representing the graph
    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4},
    };

    findMinimumSpanningTree(edges, V, E);

    return 0;
}
