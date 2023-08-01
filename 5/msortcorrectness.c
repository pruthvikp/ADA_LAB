#include<stdio.h>

void merge(int a[],int beg,int mid,int end){
    int n1=mid-beg+1;
    int n2=end-mid;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++)
        L[i]=a[beg+i];
    for(int j=0;j<n2;j++)
        R[j]=a[mid+1+j];
    int i=0,j=0,k=beg;
    while(i<n1 && j<n2){
        if(L[i]<=R[j])
            a[k++]=L[i++];
        else
            a[k++]=R[j++];
    }
    while(i<n1)
        a[k++]=L[i++];
    while(j<n2)
        a[k++]=R[j++];
}

void mergeSort(int a[],int beg,int end){
    if(beg<end){
        int mid=(beg+end)/2;
        mergeSort(a,beg,mid);
        mergeSort(a,mid+1,end);
        merge(a,beg,mid,end);
    }
}

int main(){
    int n,i;
    printf("Enter n: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergeSort(a,0,n-1);
    printf("Elements after sorting: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}