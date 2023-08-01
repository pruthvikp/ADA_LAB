#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int a[MAX][MAX],vis[MAX],path[MAX],cyc=0,n;
int stack[MAX],top=-1;

void topologicalSort(int v){
    vis[v]=1;
    path[v]=1;
    for(int w=0;w<n;w++){
        if(a[v][w]==1){
            if(vis[w]==1 && path[w]==1)
                cyc=1;
            if(vis[w]==0)
                topologicalSort(w);
        }
    }
    path[v]=0;
    stack[++top]=v;
}

void main(){
    int i,j;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++){
        vis[i]=0;
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    for(int v=0;v<n;v++){
        if(vis[v]==0)
            topologicalSort(v);
    }
    
    if(cyc==0){
        printf("Topological sort order of vertices: ");
        for(i=top;i>=0;i--)
            printf("-->%c ",stack[i]+65);
        printf("\n");
    }
    else
        printf("There is no solution as the graph contains cycle\n");
}
