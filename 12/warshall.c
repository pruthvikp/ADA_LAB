#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count;

void generate(int n,int **a){
    srand(time(NULL));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                a[i][j]=0;
            else if(a[j][i]==1)
                    continue;
            else a[i][j]=rand()%2;
        }
    }
}

void warshall(int n,int **a){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                count++;
                a[i][j]=(a[i][j]) || (a[i][k] && a[k][j]);
            }
        }
    }
}

void main(){
    int n=4;
    FILE *fptr;
    fptr=fopen("warshalldata.txt","a");
    while(n<10){
        int **a=malloc(sizeof(int*)*n);
        for(int i=0;i<n;i++)
            a[i]=(int*)malloc(sizeof(int)*n);
        count=0;
        generate(n,a);
        printf("The generated matrix is\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
        warshall(n,a);
        printf("The output matrix is\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
        printf("Basic operation count=%d\n",count);
        fprintf(fptr,"%d\t%d\n",n,count);
        free(a);
        n++;
    }
    fclose(fptr);
}