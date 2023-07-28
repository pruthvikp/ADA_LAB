#include<stdio.h>
#include<stdlib.h>

int vis[10],trav[10],cnt=0,cyc=0,con=0;

typedef struct queue{
    int A[15],f,r;
}q;

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
        printf("\nGraph is connected\n");
}

int main(){
    int n,j,i,cnt=0;
    q *qp=malloc(sizeof(q));
    qp->f=qp->r=-1;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    int a[n][n];
    printf("Enter the adjacency matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
    BFS(n,a,qp);
    printf("The BFS order of traversal is\n");
    for(int i=1;i<=n;i++)
        printf("-->%c",trav[i]+65);
    printf("\n");
    if(cyc==1)
        printf("Cycle exists\n");
    else
        printf("Cycle does not exist\n");
}