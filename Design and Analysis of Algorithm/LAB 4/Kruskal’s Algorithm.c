#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent an edge
struct Edge
{
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset
{
    int parent, rank;
};

// Function to find the subset of an element
int find(struct Subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent); // Path compression
    return subsets[i].parent;
}

// Function to do union of two subsets
void unionSubsets(struct Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to compare two edges based on their weight (for sorting)
int compareEdges(const void *a, const void *b)
{
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

// Kruskal's algorithm to find MST
void kruskal(struct Edge edges[], int V, int E)
{
    struct Edge result[V]; // Array to store the resultant MST
    struct Subset subsets[V];
    int e = 0; // Index for result[] and number of edges in MST
    int i = 0; // Index for sorted edges

    // Step 1: Sort all edges in non-decreasing order of their weight
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    // Create V subsets with single elements
    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Step 2: Pick the smallest edge and increment the index for next iteration
    while (e < V - 1 && i < E)
    {
        struct Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge doesn't form a cycle, include it in the result
        if (x != y)
        {
            result[e++] = next_edge;
            unionSubsets(subsets, x, y);
        }
    }

    // Step 3: Print the MST
    printf("Edges in the MST:\n");
    for (int i = 0; i < e; i++)
    {
        printf("%d - %d: %d\n", result[i].src, result[i].dest, result[i].weight);
    }
}

int main()
{
    int V, E;
    printf("\t****NISHAN DHAKAL****\n      **** Kruskal’s Algorithm ****\n\n");

    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[E];

    printf("Enter edges (source, destination, weight):\n");
    for (int i = 0; i < E; i++)
    {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskal(edges, V, E);
    return 0;
}
