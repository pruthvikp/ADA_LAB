#include<stdio.h>
#include<stdlib.h>

void main(){
    int i,j,temp,c=0,n;
    printf("Enter n:");
    scanf("%d",&n);
    int *a=malloc(sizeof(int)*n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<n;i++){
        temp=a[i];
        j=i-1;
        c++;
        while(j>=0 && temp<a[j]){
            c++;
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    printf("Elements after sorting: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}