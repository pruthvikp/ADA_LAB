#include<stdio.h>
#include<stdlib.h>

int vis[10],cnt=0,cyc=0,con=0;

void dfs(int n,int a[n][n],int v,int p){
    cnt=cnt+1;
    printf("-->%c ",v+65);
    vis[v]=cnt;
    for(int w=0;w<n;w++){
        if(a[v][w]==1){
            if(vis[w]!=0 && w!=p)
                cyc=1;
            if(vis[w]==0) 
                dfs(n,a,w,v);
        }
    }
}

void DFS(int n,int a[n][n]){
    for(int v=0;v<n;v++)
        vis[v]=0;
    dfs(n,a,0,-1);
    if(cnt!=n){
        for(int v=1;v<n;v++){
            if(vis[v]==0){
                con=1;
                printf("\n");
                dfs(n,a,v,-1);
            }
        }
        printf("\nGraph is disconnected and the above are the connected components\n");
    }
    if(con==0)
        printf("\nGraph is connected\n");
}

int main(){
    int n,j,i;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    
    int a[n][n];
    
    printf("Enter the adjacency matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
                
    DFS(n,a);
    printf("The DFS order of traversal is\n");
    for(int i=0;i<n;i++)
        printf("-->%c",vis[i]+64);
    printf("\n");
    if(cyc==1)
        printf("Cycle exists\n");
    else
        printf("Cycle does not exist\n");

}