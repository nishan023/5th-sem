#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Function to add an edge to the graph
void addEdge(int graph[MAX_VERTICES][MAX_VERTICES], int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}

// Function to print the vertex cover set
void printVertexCover(int vertexCover[MAX_VERTICES], int V)
{
    printf("Vertex Cover: ");
    for (int i = 0; i < V; i++)
    {
        if (vertexCover[i] == 1)
            printf("%d ", i);
    }
    printf("\n");
}

// Greedy approach for Vertex Cover
void vertexCover(int graph[MAX_VERTICES][MAX_VERTICES], int V)
{
    int vertexCover[MAX_VERTICES] = {0}; // Initialize all vertices as not in the cover

    // Go through all edges and add the endpoints of each edge to the vertex cover
    for (int u = 0; u < V; u++)
    {
        for (int v = u + 1; v < V; v++)
        {
            if (graph[u][v] == 1)
            { // If there's an edge between u and v
                // If u or v is not yet in the vertex cover, add them
                if (vertexCover[u] == 0 && vertexCover[v] == 0)
                {
                    vertexCover[u] = 1;
                    vertexCover[v] = 1;
                }
            }
        }
    }

    // Print the result
    printVertexCover(vertexCover, V);
}

int main()
{
    int V, E, u, v;
    printf("\t****NISHAN DHAKAL****\n      **** Vertex Cover Problem ****\n\n");

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Initialize graph to 0

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    vertexCover(graph, V);

    return 0;
}
