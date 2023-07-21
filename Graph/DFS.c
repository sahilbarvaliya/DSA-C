#include <stdio.h>

int visited[10], n = 8, order[10], k = 0;

int adj[8][8] = {
    {0, 1, 0, 1, 0, 0, 0, 0},
    {1, 0, 0, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 1, 0, 1, 0},
    {1, 1, 0, 0, 0, 1, 0, 1},
    {0, 0, 1, 0, 0, 0, 1, 1},
    {0, 1, 0, 1, 0, 0, 1, 0},
    {0, 0, 1, 0, 1, 0, 0, 1},
    {0, 0, 0, 1, 1, 0, 1, 0},
};

void dfs(int v)
{
    int i;
    visited[v] = 1;
    for (i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
            dfs(i);
    }
    order[k++] = v;
}

int main()
{
    int i, j;

    for (i = 0; i < n; i++)
        visited[i] = 0;
    for (i = 0; i < n; i++)
        if (visited[i] == 0)
            dfs(i);
    printf("The topological order is\n");
    for (i = n - 1; i >= 0; i--)
        printf("%d\t", order[i]);

    return 0;
}