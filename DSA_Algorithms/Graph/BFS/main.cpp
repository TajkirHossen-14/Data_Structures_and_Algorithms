// Breadth-First Search

#include<stdio.h>
#include<queue>

int V = 5;
int Visited[5] = {0};

int G[5][5] = {
              {0,1,0,0,1},
              {1,0,0,1,1},
              {0,0,0,1,0},
              {0,1,1,0,1},
              {1,1,0,1,0}
              };

void BFS(int v)
{
    std::queue<int> Q;

    Visited[v] = 1;                // v = Starting Node / Vertex

    printf("%d ", v);
    Q.push(v);

    while(!Q.empty())
    {
        int Current = Q.front();
        Q.pop();

        for(int j = 0; j < V; j++)
        {
            if(G[Current][j] == 1 && Visited[j] == 0)
            {
                Visited[j] = 1;

                printf("->%d ", j);
                Q.push(j);
            }
        }
    }
}

int main()
{
    printf("BFS Traversal Output : ");

    BFS(0);

    printf("\n");
}
