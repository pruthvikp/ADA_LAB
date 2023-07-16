// Topological sorting using source removal
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int q[MAX], front = 0, rear = -1;

int indegree(int src, int n, int graph[][MAX])
{
    int ct = 0;
    for (int j = 0; j < n; j++)
        ct += graph[j][src];
    return ct;
}

void enqueue(int i)
{
    q[++rear] = i;
    printf("-->%c ", i + 65);
}

int dequeue()
{
    return q[front++];
}

int isEmpty()
{
    if (front > rear)
        return 1;
    return 0;
}

void topo(int graph[][MAX], int *indeg, int n)
{
    int i, j, k, count = 0;
    printf("The topological sort order is: ");
    for (i = 0; i < n; i++)
    {
        indeg[i] = indegree(i, n, graph);
        if (indeg[i] == 0)
            enqueue(i);
    }
    while (count < n)
    {
        if (isEmpty())
        {
            printf("Error: As Queue is empty,Cycle exists in the graph and hence it is not a DAG\n ");
            return;
        }

        // dequeue source vertex with indegree=0 from the queue
        int src = dequeue();

        // removing src from ele to any other vertex
        for (k = 0; k < n; k++)
        {
            if (graph[src][k])
            {
                graph[src][k] = 0;
                indeg[k]--;
                if (indeg[k] == 0)
                    enqueue(k);
            }
        }

        count++;
    }
}

void main()
{
    int graph[MAX][MAX], indeg[MAX], i, j, k, n;
    printf("\nEnter the number of nodes in the graph:\n");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
        indeg[i] = 0;
    }
    topo(graph, indeg, n);
}
