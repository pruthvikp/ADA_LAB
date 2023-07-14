//Traversal
#include<stdio.h>
#include<stdlib.h>

int vis[10];

void dfs(int n,int a[n][n],int v,int cnt){
    printf("-->%c ",v+65);
    vis[v]=cnt;
    for(int w=0;w<n;w++)
        if(a[v][w]==1 && vis[w]==0)
            dfs(n,a,w,++cnt);
}

void DFS(int n,int a[n][n]){
    for(int v=0;v<n;v++)
        vis[v]=0;
    int cnt=0;
    for(int v=0;v<n;v++)
        if(vis[v]==0)
            dfs(n,a,v,++cnt);
}

int main(){
    int n,j,i,cnt=0;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    int a[n][n];
    printf("Enter the adjacency matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
    printf("The DFS order of traversal is\n");
    DFS(n,a);
}
