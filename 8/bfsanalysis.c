#include<stdio.h>
#include<stdlib.h>

int vis[10],trav[10],cnt,con,cyc,boc;

typedef struct queue{
    int A[15],f,r;
}q;

int generate(int n,int a[n][n],int ch){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ch==0){
                if(j==i+1)
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

int isEmpty(q* qp){
    if(qp->f==-1 && qp->r==-1)
        return 1;
    return 0;
} 

void enq(q *qp,int data){
    printf("-->%c",data+65);
    trav[cnt]=data;
    if(isEmpty(qp))
        qp->f=0;
    qp->A[++qp->r]=data;
}

void deq(q *qp){
    qp->f++;
    if(qp->f > qp->r)
        qp->f=qp->r=-1;
}

void bfs(int n,int a[n][n],int v,int p, q *qp){
    cnt=cnt+1;
    vis[v]=cnt;
    enq(qp,v);
    while(!isEmpty(qp)){
        for(int w=0;w<n;w++){
            if(a[qp->A[qp->f]][w]==1){
                boc++;
                if(vis[w]!=0 && w!=p){
                    cyc=1;
                }
                if(vis[w]==0){
                    cnt=cnt+1;
                    vis[w]=cnt;
                    enq(qp,w);
                }
            }
        }
        deq(qp);
    }
}


void BFS(int n,int a[n][n],q *qp){
    for(int v=0;v<n;v++)
        vis[v]=0;
    bfs(n,a,0,-1,qp);
    if(cnt!=n){
        for(int v=1;v<n;v++)
            if(vis[v]==0){
                con=1;
                printf("\n");
                bfs(n,a,v,-1,qp);
            }
        printf("\nGraph is disconnected and the above are the connected components\n");
    }
    if(con==0)
        printf("\nGraph is connected and the above is the BFS order of traversal\n");
}

int main(){
    int n=4,j,i,ch;
    q *qp=malloc(sizeof(q));
    qp->f=qp->r=-1;
    FILE *fptr;
    fptr=fopen("bfsdata.txt","a");
    while(n<10){
        int a[n][n];
        for(ch=0;ch<2;ch++){
            cnt=0,con=0,cyc=0,boc=0;
            if(ch==0) printf("\nBEST CASE\n");
            else printf("\nWORST CASE\n");
            generate(n,a,ch); 
            printf("The adjacency matrix is:\n");
            for(i=0;i<n;i++){
                for(j=0;j<n;j++)
                        printf("%d ",a[i][j]);
                printf("\n");
            }       
            BFS(n,a,qp);
            fprintf(fptr,"%d\t%d\t",n,boc);
            if(con==1){
                printf("The BFS order of traversal is\n");
                for(int i=1;i<=n;i++)
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
