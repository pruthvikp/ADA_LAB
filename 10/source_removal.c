#include <stdio.h>
#include <stdlib.h>
//LEgand
int a[100][100];
int in[100], v[100], s[100], t[100]; //
int f = 0, r = -1;                   //
int n, scount = 0;
computeindegree()
{
    for (int i = 0; i < n; i++)
    {
        in[i] = 0;
        v[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j][i] == 1)
            {
                in[i]++;
            }
        }
        // printf("%d\t%d\n", i, in[i]);
        if (in[i] == 0)
        {
            // printf("\n%d", i);
            scount++;
            s[++r] = i;
            v[i] = 1;
        }
    }
}
void topo()
{
    int cnt = 0;
    while (scount != 0)
    {
        int src = s[f++];
        scount--;
        t[cnt] = src;
        cnt++;
        for (int i = 0; i < n; i++)
        {
            if (a[src][i] == 1)
            {
                in[i]--;
            }
            if (in[i] == 0 && v[i] == 0)
            {
                scount++;
                v[i] = 1;
                s[++r] = i;
            }
        }
    }
    if (cnt != n)
    {
        printf("Cycle Exist");
    }
    else
    {
        printf("\nThe topological sorting is\n");
        for (int i = 0; i < n; i++)
            printf("%d\t", s[i] + 1);
    }
}
void main()
{
    int i, j;
    printf("enter the number of vertices:");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    computeindegree();
    topo();
}
