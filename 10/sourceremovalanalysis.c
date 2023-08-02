#include<stdio.h>
#include<stdlib.h>

#define MAX 15

int a[MAX][MAX],indegree[MAX],trav[MAX],n=4,k,cyc=0,count;
int queue[MAX],front=-1,rear=-1;

void generate(){
    for(int i=0;i<n;i++){
        indegree[i]=0;
        for(int j=0;j<n;j++){
            if(j==i+1)
                a[i][j]=1;
            else 
                a[i][j]=0;
        }
    }
}

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
    int data=queue[front++];
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
    for(int cnt=0;cnt<n;cnt++){
        if(isEmpty()){
            cyc=1;
            return;
        }
        int i=dequeue();
        for(int j=0;j<n;j++){
            count++;
            if(a[i][j]==1){
                a[i][j]=0;
                indegree[j]--;
                if(indegree[j]==0)
                    enqueue(j);
            }
        }
    }

}

void main(){
    int i,j;
    FILE *fptr=fopen("sourcedata.txt","a");
    while(n<11){
        count=0,k=0,cyc=0;
        generate();
        printf("The generated matrix is:\n");
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
        sourceRemoval();
        if(cyc==0){
            printf("The topological sorting order is: ");
            for(i=0;i<n;i++)
                printf("-->%c ",trav[i]+65);
        }
        else
            printf("There is no solution as the graph contains cycle\n");
        fprintf(fptr,"%d\t%d\n",n,count);
        printf("\nBasic operation count=%d\n\n",count);
        n++;
    }
    fclose(fptr);
}
