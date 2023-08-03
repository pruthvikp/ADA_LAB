#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int a[MAX][MAX],opt[MAX],k;

typedef struct table{
    int item,value,weight;
}T;

int max(int a, int b){
    return a>b?a:b;
}

void knapsack(T *t,int n,int w){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 || j==0)
                a[i][j]=0;
            else{
                if(j<t[i].weight)
                    a[i][j]=a[i-1][j];
                else
                    a[i][j]=max(a[i-1][j], (t[i].value + a[i-1][j-t[i].weight]) );              
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
    int n=4,w=5,i;
    T *t=malloc(sizeof(T)*(n+1));
    printf("Enter item's weight and and value\nWt Val\n");
    for(i=1;i<=n;i++){
        printf("hi");
        t[i].item=i;
        printf("hi");
        scanf("%d",&t[i].weight);
        scanf("%d",&t[i].value);
        printf("hi");
    }
    printf("hi");
    knapsack(t,n,w);
    printf("hi");
    composition(t,n,w);
    printf("Optimal value=%d\n",a[n][w]);
    printf("Optimal set: ");
    for(i=0;i<k;i++)
        printf("%d ",opt[i]);
    printf("\n");
}
