#include<stdio.h>
#include<stdlib.h>

int vis[15],cnt,cyc,con,trav[15],boc;

int generate(int n,int a[n][n],int ch){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ch==0){
                if((i+1)==j)
                    a[i][j]=1;
                else 
                    a[i][j]=0;
            }
            else{
                if(i==j)
                    a[i][j]=0;
                else
                    a[i][j]=1;
            }
        }
    }
}

void dfs(int n,int a[n][n],int v,int p){
    trav[cnt]=v;
    cnt=cnt+1;
    printf("-->%c ",v+65);
    vis[v]=cnt;
    for(int w=0;w<n;w++){
        if(a[v][w]==1){
            boc++;
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
        printf("\nGraph is connected and the above is the order of DFS traversal\n");
}

int main(){
    int n=4,j,i,ch;
    FILE *fptr;
    fptr=fopen("dfsdata.txt","a");
    while(n<11){
    int a[n][n];
    for(ch=0;ch<2;ch++){
        cnt=0,cyc=0,con=0,boc=0;
        generate(n,a,ch);
        if(ch==0)
            printf("\nBEST CASE\n");
        else 
            printf("\nWORST CASE\n");
        printf("The adjacency matrix is:\n");
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                    printf("%d ",a[i][j]);
            printf("\n");
        }
        DFS(n,a);
        fprintf(fptr,"%d\t%d\t",n,boc);
        if(con==1){
            printf("The DFS order of traversal is\n");
            for(int i=0;i<n;i++)
                printf("-->%c",trav[i]+65);
            printf("\n");
        }
        if(cyc==1)
            printf("Cycle exists\n");
        else
            printf("Cycle does not exist\n");
        printf("Basic operation count=%d\n",boc);
    }
    fprintf(fptr,"\n");
    n++;
    }
}
