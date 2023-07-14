#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define INF 999

int a[20][20],count=0;

int min(int a,int b){
    return a<b?a:b;
}

void floyd(int n){
    int t=0;
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                count++;
                a[i][j]=min(a[i][j], a[i][k]+a[k][j]);
            }
}

void floyd_fine(int n){
    int t=0;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            t=a[i][k];
            for(int j=0;j<n;j++){
                count++;
                if(t<a[i][j])
                    a[i][j]=min(a[i][j], t+a[k][j]);
            }
        }
    }
}

void main(){
    int n;
    srand(time(NULL));
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(i==j)
                a[i][j]=0;
            else if(j==i+1)
                a[i][j]=INF;
            else 
                a[i][j]=(rand()%9)+1;
        }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
    printf("\n");
    floyd_fine(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
    printf("Count= %d\n",count);
}
