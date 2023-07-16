// DFS Toplogical Sorting

#include <stdio.h>
#include <stdlib.h>
int n, stk[20], tos = -1;

void dfs(int graph[][n], int v, int *vis)
{
    vis[v] = 1;
    for (int next = 0; next < n; next++)
    {
        if (graph[v][next] && !vis[next])
            dfs(graph, next, vis);
    }
    stk[++tos] = v;
}

void main()
{
    printf("Enter no of vertices\n");
    scanf("%d", &n);
    int graph[n][n];
    printf("Adjacency matrix>>\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }
    int *vis = (int *)malloc(sizeof(int) * n);
    for(int i=0;i<n;i++)
        vis[i]=0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(graph, i, vis);
    }
    printf("Topological sorting\n");
    for (int i = tos; i >= 0; --i)
        printf("%d\n", stk[i]);
}
