#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int *a,int l,int r){
    int p=a[l],i=l+1,j=r;
    while(i<=j){
        while(i<=r && a[i]<p)
            i++;
        while(j>=i && a[j]>p)
            j--;
        if(i<=j){
            swap(&a[i],&a[j]);
            i++;
            j--;
        }
    }
    swap(&a[l],&a[j]);    
    return j;
}

void quickSort(int *a,int l,int r){
    int s;
    if(l<r){
        s=partition(a,l,r);
        quickSort(a,l,s-1);
        quickSort(a,s+1,r);
    }
}

void main(){
    int n,i;
    printf("Enter n:");
    scanf("%d",&n);
    int *a=malloc(sizeof(int)*n);
    printf("Enter array:");
    for(i=0;i<n;i++)
        scanf("%d",(a+i));
    quickSort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d\t",*(a+i));
}