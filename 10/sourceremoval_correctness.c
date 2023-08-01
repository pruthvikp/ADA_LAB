#include<stdio.h>
#include<stdlib.h>

#define MAX 15

int a[MAX][MAX],indegree[MAX],trav[MAX],n,k,cyc=0;
int queue[MAX],front=-1,rear=-1;

int isEmpty(){
    if(front==-1 && rear==-1)
        return 1;
    return 0;
}

void enqueue(int data){
    trav[k++]=data;
    if(isEmpty())
        front=0;
    queue[++rear]=data;  
}

int dequeue(){
    int data=queue[front];
    front++;
    if(front>rear)
        front=rear=-1;
    return data;
}

void indeg(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[j][i]==1)
                indegree[i]++;
        }
        if(indegree[i]==0)
            enqueue(i);
    }
}

void sourceRemoval(){
    indeg();
    int count=0;

    while(count<n){

        if(isEmpty()){
            cyc=1;
            return;
        }

        int i=dequeue();

        for(int j=0;j<n;j++){
            if(a[i][j]==1){
                a[i][j]=0;
                indegree[j]--;
                if(indegree[j]==0)
                    enqueue(j);
            }
        }
        count++;
    }
}

void main(){
    int i,j;
    printf("Enter number of vertices\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    for(i=0;i<n;i++){
        indegree[i]=0;
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    sourceRemoval();
    
    if(cyc==0){
        printf("The topological sorting order(using source removal method) is\n");
        for(i=0;i<n;i++)
            printf("-->%c ",trav[i]+65);
    }
    else
        printf("There is no solution as the graph contains cycle\n");
}