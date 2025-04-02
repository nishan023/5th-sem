#include <stdio.h>
#include <limits.h>

#define MAX 100

// Function to find the vertex with the minimum distance value
int minDist(int dist[], int sptSet[], int V)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] < min)
        {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

// Function to implement Dijkstra's Algorithm
void dijkstra(int graph[MAX][MAX], int V, int src)
{
    int dist[V], sptSet[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDist(dist, sptSet, V);
        sptSet[u] = 1;
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tDistance from Source %d\n", src);
    for (int i = 0; i < V; i++)
    {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main()
{
    int V, src;
    printf("\n\t****NISHAN DHAKAL****\n      **** Dijkstra's Algorithm ****\n\n");
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    int graph[MAX][MAX];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, V, src);
    return 0;
}
