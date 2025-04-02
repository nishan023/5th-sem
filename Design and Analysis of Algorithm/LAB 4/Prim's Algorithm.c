#include <stdio.h>
#include <limits.h>

#define MAX 100

// Function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[], int V)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    return min_index;
}

// Function to implement Prim's Algorithm
void primMST(int graph[MAX][MAX], int V)
{
    int parent[V], key[V], mstSet[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet, V);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
    printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

int main()
{
    int V;
    printf("\t****NISHAN DHAKAL****\n      **** Prim's Algorithm ****\n\n");
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[MAX][MAX];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, V);
    return 0;
}
