#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int a[MAX][MAX],vis[MAX],path[MAX],cyc=0,n=4,count;
int stack[MAX],top=-1;

void generate(){
    for(int i=0;i<n;i++){
        vis[i]=0;
        for(int j=0;j<n;j++){
            if(j==i+1)
                a[i][j]=1;
            else 
                a[i][j]=0;            
        }
    }
}

void topologicalSort(int v){
    vis[v]=1;
    path[v]=1;
    for(int w=0;w<n;w++){
        count++;
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
    FILE *fptr;
    fptr=fopen("topodata.txt","a");
    while(n<11){
        count=0,top=-1;
        generate(n);
        printf("The adjacency matrix is:\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
        for(int v=0;v<n;v++){
            if(vis[v]==0)
                topologicalSort(v);
        }
        if(cyc==0){
            printf("Topological sort order of vertices: ");
            for(int i=top;i>=0;i--)
                printf("-->%c ",stack[i]+65);
            printf("\n");
        }
        else
            printf("There is no solution as the graph contains cycle\n");
        printf("Basic operation count=%d\n",count);
        fprintf(fptr,"%d\t%d\n",n,count);
        n++;
    }
    fclose(fptr);
}
