#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define I 999

int count;

int min(int a,int b){
    return (a<b)?a:b;
}

void generate(int **a,int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(i==j)
                a[i][j]=0;
            else if(j==i+1)
                a[i][j]=I;
            else 
                a[i][j]=(rand()%9)+1;
        }
}

void floyd(int **a,int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                count++;
                a[i][j]=min(a[i][j], a[i][k]+a[k][j]);
            }
        }
    }
}

void main(){
    int i,j,n=4;
    FILE *fptr=fopen("floyddata.txt","a");
    while(n<10){
        int **a=malloc(sizeof(int*)*n);
        for(i=0;i<n;i++)
            a[i]=malloc(sizeof(int)*n);
        generate(a,n);
        printf("Generated matrix:\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                printf("%d\t",a[i][j]);
            printf("\n");
        }
        count=0;
        floyd(a,n);
        printf("Output matrix:\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                printf("%d  ",a[i][j]);
            printf("\n");
        }
        fprintf(fptr,"%d\t%d\n",n,count);
        printf("Basic operation count is: %d\n\n",count);
        free(a);
        n++;
    }
}