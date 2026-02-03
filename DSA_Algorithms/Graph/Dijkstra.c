// Dijkstra

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#define V 5

int Findu(int Dist[], bool VisitedNode[])
{
    int Min_Distance = INT_MAX, Min_Node;

    for (int v = 0; v < V; v++)
    {
        if (!VisitedNode[v] && Dist[v] < Min_Distance)
        {
            Min_Distance = Dist[v];
            Min_Node = v;
        }
    }
    return Min_Node;
}

void PrintSolution(int Dist[])
{
    printf("\nVertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, Dist[i]);
}

void Dijkstra(int Graph[V][V], int Src)
{
    int Dist[V];
    bool VisitedNode[V];

    for (int i = 0; i < V; i++)
        Dist[i] = INT_MAX, VisitedNode[i] = false;

    Dist[Src] = 0;

    for (int Count = 0; Count < V - 1; Count++)
    {
        int u = Findu(Dist, VisitedNode);

        VisitedNode[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!VisitedNode[v] && Graph[u][v] && Dist[u] != INT_MAX
                && Dist[u] + Graph[u][v] < Dist[v])
            {
                Dist[v] = Dist[u] + Graph[u][v];
            }
        }
    }
    PrintSolution(Dist);
}

int main()
{
    int Graph[V][V] = {
                      { 0, 0, 0, 0, 1 },
                      { 0, 0, 0, 3, 6 },
                      { 3, 2, 0, 7, 0 },
                      { 0, 0, 0, 0, 5 },
                      { 0, 0, 0, 0, 0 }
                      };

    int Source = 2;

    Dijkstra(Graph, Source);

    return 0;
}
