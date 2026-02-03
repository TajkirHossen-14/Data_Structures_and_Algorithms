#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 10                     // Define number of vertices in the graph


int MinKey(int key[], bool mstSet[])       // Function to find the vertex with the minimum key value
{
    int Min = INT_MAX, Min_Index;

    for (int v = 0; v < V; v++)            // Loop through all vertices
    {
        if (mstSet[v] == false && key[v] < Min)    // If vertex v is not in MST and has a smaller key value
        {
            Min = key[v], Min_Index = v;           // Update minimum value and index
        }
    }
    return Min_Index;
}

void PrintMST(int Parent[], int Graph[V][V])   // Function to print the constructed MST and total cost
{
    int TotalCost = 0;

    printf("Edge \tWeight\n");           // Print header for MST edges

    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d\n", Parent[i], i, Graph[i][Parent[i]]);    // Print edge and its weight
        TotalCost += Graph[i][Parent[i]];                              // Add edge weight to total cost
    }
    printf("\nMinimum Total Cost = %d\n", TotalCost);
}

void Prim(int Graph[V][V])         // Function to construct and print MST using Prim's algorithm
{
    int Parent[V];                // Array to store MST
    int key[V];                   // Key values to pick minimum weight edge
    bool mstSet[V];               // To represent set of vertices in MST

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX, mstSet[i] = false;
    }
    key[0] = 0;                // Start from the first vertex
    Parent[0] = -1;            // First node is always root of MST

    for (int count = 0; count < V - 1; count++)
    {
        int u = MinKey(key, mstSet);         // Pick vertex with minimum key value
        mstSet[u] = true;

        for(int v = 0; v < V; v++)
        {
            if (Graph[u][v] && mstSet[v] == false && Graph[u][v] < key[v])    // If there is an edge from u to v,
            {                                                                 // v is not in MST, and weight is less than current key
                Parent[v] = u, key[v] = Graph[u][v];          // Update Parent and Key
            }
        }

    }
    PrintMST(Parent, Graph);
}

int main()
{
    int Graph[V][V] = { {0, 4, 0, 3, 0, 0, 6, 0, 0, 0},  // A
                        {4, 0, 5, 5, 3, 2, 0, 0, 0, 0},  // B
                        {0, 5, 0, 0, 0, 2, 0, 0, 0, 4},  // C
                        {3, 5, 0, 0, 0, 0, 4, 2, 0, 0},  // D
                        {0, 3, 0, 0, 0, 2, 0, 6, 4, 0},  // E
                        {0, 2, 2, 0, 2, 0, 0, 0, 0, 5},  // F
                        {6, 0, 0, 4, 0, 0, 0, 3, 0, 0},  // G
                        {0, 0, 0, 2, 6, 0, 3, 0, 5, 0},  // H
                        {0, 0, 0, 0, 4, 0, 0, 5, 0, 3},  // I
                        {0, 0, 4, 0, 0, 5, 0, 0, 3, 0},  // J
                      };

    Prim(Graph);

    return 0;
}
