#include <stdio.h>

#define MAX 100
#define INF 9999

int parent[MAX];
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];

    return i;
}

void unionSet(int i, int j)
{
    int a = find(i);
    int b = find(j);

    parent[a] = b;
}


void kruskal(int graph[MAX][MAX], int n)
{
    int edges = 0, minCost = 0;
    int u, v, min, i, j;

    for (i = 0; i < n; i++)
        parent[i] = i;

    printf(" Kruskal's Algorithm ");
    printf("Edges in Minimum Spanning Tree:\n");

    while (edges < n - 1)
    {
        min = INF;
        u = v = -1;

        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (graph[i][j] != 0 && graph[i][j] < min)
                {
                    if (find(i) != find(j))
                    {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1)
        {
            printf("MST cannot be formed.\n");
            return;
        }

        unionSet(u, v);

        printf("%d - %d : %d\n", u + 1, v + 1, min);

        minCost += min;
        edges++;
    }

    printf("Minimum Cost = %d\n", minCost);
}

void prim(int graph[MAX][MAX], int n)
{
    int selected[MAX] = {0};
    int edges = 0, minCost = 0;
    int x, y, min, i, j;

    selected[0] = 1;

    printf("Prim's Algorithm");
    printf("Edges in Minimum Spanning Tree:\n");

    while (edges < n - 1)
    {
        min = INF;
        x = y = -1;

        for (i = 0; i < n; i++)
        {
            if (selected[i])
            {
                for (j = 0; j < n; j++)
                {
                    if (!selected[j] &&
                        graph[i][j] != 0 &&
                        graph[i][j] < min)
                    {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if (x == -1)
        {
            printf("MST cannot be formed.\n");
            return;
        }

        printf("%d - %d : %d\n", x + 1, y + 1, min);

        minCost += min;
        selected[y] = 1;
        edges++;
    }

    printf("Minimum Cost = %d\n", minCost);
}

int main()
{
    int graph[MAX][MAX];
    int n, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    printf("(Enter 0 if there is no edge)\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    kruskal(graph, n);
    prim(graph, n);

    return 0;
}

