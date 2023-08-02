#include<stdio.h>
#include<stdlib.h>

int a[20][20],count=0;

void warshall(int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                count++;
                a[i][j]=(a[i][j] || (a[i][k] && a[k][j]));
            }
        }
    }
}

void warshall_fine(int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            count++;
            if(a[i][k]==1){
                for(int j=0;j<n;j++){
                    count++;
                    if(a[i][j]!=1)
                        a[i][j]=(a[i][k] && a[k][j]);
                }
            }
        }
    }
}

void main(){
    int n;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the matrix\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    warshall(n);
    printf("The output matrix\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("%d  ",a[i][j]);
        printf("\n");
    }
    printf("Count= %d\n",count);
}
