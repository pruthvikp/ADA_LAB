#include<stdio.h>
#include<stdlib.h>

int a[20][20];

int min(int a,int b){
    return a<b?a:b;
}

void floyd(int n){
    int t=0;
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                a[i][j]=min(a[i][j], a[i][k]+a[k][j]);
            }
}

void floyd_fine(int n){
    int t=0;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            t=a[i][k];
            for(int j=0;j<n;j++){
                if(t<a[i][j])
                    a[i][j]=min(a[i][j], t+a[k][j]);
            }
        }
    }
}

void main(){
    int n;
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    printf("Enter the matrix\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    floyd_fine(n);
    printf("Output matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
}