#include<stdio.h>
#include<stdlib.h>

int vis[10],cyc=0;

void dfs(int n,int a[n][n],int v,int p,int cnt){
    printf("-->%c ",v+65);
    vis[v]=cnt;
    for(int w=0;w<n;w++){
        if(a[v][w]==1){
            if(vis[w]!=0 && w!=p)
                cyc=1;
            else {
                dfs(n,a,w,v,++cnt);
            }
        }
    }
}

void DFS(int n,int a[n][n]){
    for(int v=0;v<n;v++)
        vis[v]=0;
    int cnt=0,con=0;
    for(int v=0;v<n;v++)
        if(vis[v]==0)
            dfs(n,a,v,-1,++cnt);
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
    printf("\n");
    if(cyc==1)
        printf("Cycle exists\n");
    else
        printf("Cycle does not exist\n");

}