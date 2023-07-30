#include<stdio.h>
#include<stdlib.h>

void main(){
    int i,j,temp,c=0,min,n;
    printf("Enter n:");
    scanf("%d",&n);
    int *a=malloc(sizeof(int)*n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i;j<n;j++){
            if(a[j]<a[min])
                min=j;
        }
        if(min!=i){
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
    printf("Elements after sorting: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}