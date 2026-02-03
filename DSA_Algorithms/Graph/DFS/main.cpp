// Depth First Search

#include<stdio.h>
#include <stack>

int V = 5;
int Visited[5] = {0};

int G[5][5] = {
              {0,1,0,0,1},
              {1,0,0,1,1},
              {0,0,0,1,0},
              {0,1,1,0,1},
              {1,1,0,1,0}
              };

void DFS(int v)
{
    std::stack<int> S;

    Visited[v] = 1;                // v = Starting Node / Vertex
    printf("%d", v);

    S.push(v);

    while(!S.empty())
    {
        int Current = S.top();
        S.pop();
        for(int j = 0; j < V; j++)
        {
            if(G[Current][j] == 1 && Visited[j] == 0)
            {
                Visited[j] = 1;
                printf("->%d", j);
                S.push(j);
            }
        }
    }
}
int main()
{
    printf("DFS Traversal Output : ");

    DFS(0);

    printf("\n");
}
