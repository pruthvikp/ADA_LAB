#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int a[20][20],opt[20],count=0,i=0,k=0;

typedef struct table{
    int item,value,weight;
}T;

int max(int a,int b){
    return a>b?a:b;
}

void knapsack(T *t,int n,int w){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            // count++;
            if(i==0 || j==0)
                a[i][j]=0;
            else{
                count++;
                if(j<t[i].weight)
                    a[i][j]=a[i-1][j];
                else
                    a[i][j]=max(a[i-1][j], (t[i].value+a[i-1][j-t[i].weight]));
            }
        }
    }
}

void composition(T *t,int n,int w){
    int rc=w;
    k=0;
    for(int i=n;i>0;i--){
        if(a[i][rc]!=a[i-1][rc]){
            opt[k++]=i;
            rc=rc-t[i].weight;
        }
        if(rc==0)
            break;
    }
}

void main(){
    int n=4,w=5;
    srand(time(NULL));
    T *t=malloc(sizeof(T)*(n+1));
    for(i=1;i<=n;i++){
        t[i].item=i;
        t[i].weight=(rand()%4)+1;
        t[i].value=rand()%50;
        printf("%d\t%d\t%d\n",t[i].item,t[i].weight,t[i].value);
    }
    knapsack(t,n,w);
    composition(t,n,w);
    printf("optimal value= %d\n",a[n][w]);
    printf("the optimal set:");
    for(i=0;i<k;i++)
        printf(" %d ",opt[i]);
    printf("\n");
    printf("Count= %d\n",count);
}