#include<stdio.h>
#include<stdlib.h>

void main(){
    int n,i,j,temp;
    printf("Enter n:");
    scanf("%d",&n);
    int *a=malloc(sizeof(int)*n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("Elements after sorting: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}