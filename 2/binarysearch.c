#include<stdio.h>
#include<stdlib.h>

int binarySearch(int *a,int key,int low,int high,int c){
    if(high>=low){
        int mid=(low+high)/2;
        if(key==a[mid])
            return c;
        if(key<a[mid])
            return binarySearch(a,key,low,mid-1,++c);
        else
            return binarySearch(a,key,mid+1,high,++c);
    }
    return c;
}

int main(void){
    int n=1,c;
    FILE *fptr;
    fptr=fopen("binarysearchdata.txt","a");
    while(n<40001){
        if(n<10000)
            n*=10;
        else n*=2;
        int *a=malloc(sizeof(int)*n);
        for(int i=0;i<n;i++)
            *(a+i)=i+1;
        //BEST CASE
        c=0;
        c=binarySearch(a,*(a+((n-1)/2)),0,n-1,++c);
        fprintf(fptr,"%d\t%d\t",n,c);
        //WORST CASE
        c=0;
        c=binarySearch(a,*(a+0),0,n-1,++c);
        fprintf(fptr,"%d\n",c);
    }
    fclose(fptr);
}