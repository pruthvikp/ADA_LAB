//not working

#include<stdio.h>
#include<stdlib.h>
//boc=basic opn cnt
int a[4][4],n,vis[10],cnt=0,cyc=0,con=0,boc;

void generate(int ch){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ch==0){
                if(i==j){
                    a[i][j]=0;}
                else a[i][j]=1;
            }
            else{
                if(i==j-1)
                    a[i][j]=1;
                else {a[i][j]=0;}
            }
        }
    }
}

void dfs(int v,int p){
    cnt=cnt+1;
    printf("-->%c ",v+65);
    vis[v]=cnt;
    for(int w=0;w<n;w++){
        if(a[v][w]==1){
            boc++;
            if(vis[w]!=0 && w!=p)
                cyc=1;
            if(vis[w]==0) 
                dfs(w,v);
        }
    }
}

void DFS(){
    for(int v=0;v<n;v++)
        vis[v]=0;
    dfs(0,-1);
    if(cnt!=n){
        for(int v=1;v<n;v++){
            if(vis[v]==0){
                con=1;
                printf("\n");
                dfs(v,-1);
            }
        }
        printf("\nGraph is disconnected and the above are the connected components\n");
    }
    if(con==0)
        printf("\nGraph is connected\n");
}



int main(){
    int n=4,j,i;
    FILE *fptr;
    fptr=fopen("dfsdata.txt","a");
    while(n<5){
        //BEST CASE
        printf("BEST CASE\nThe matrix is:\n");
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            // if(ch==0){
                if(i==j-1)
                    a[i][j]=1;
                else a[i][j]=0;
        }
    }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("%d\t",a[i][j]);}
            printf("\n");
        }
        boc=0;            
        DFS();
        fprintf(fptr,"%d\t%d\t",n,boc);
        printf("The DFS order of traversal is\n");
        for(int i=0;i<n;i++)
            printf("-->%c",vis[i]+64);
        printf("\n");
        if(cyc==1)
            printf("Cycle exists\n");
        else
            printf("Cycle does not exist\n");
        //WORST CASE
        printf("WORST CASE\nThe matrix is:\n");
for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            // if(ch==0){
                if(i==j)
                    a[i][j]=0;
                else a[i][j]=1;
        }
    }        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("%d ",a[i][j]);}
            printf("\n");
        }
        boc=0;            
        DFS();
        fprintf(fptr,"%d\n",boc);
        printf("The DFS order of traversal is\n");
        for(int i=0;i<n;i++)
            printf("-->%c",vis[i]+64);
        printf("\n");
        if(cyc==1)
            printf("Cycle exists\n");
        else
            printf("Cycle does not exist\n");

        n++;
    }
    
    fclose(fptr);
}