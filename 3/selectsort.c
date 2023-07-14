#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

int selectionSort(int *a,int n){
    int i,j,min,count=0;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n-1;j++){
            count++;
            if(a[j]<a[min])
                min=j;
        }
        if(min!=i)
            swap(&a[min],&a[i]);
    }
    return count;
}

void main(){
    FILE *fptr;
    int n=1,c;
    fptr=fopen("selectsortdata.txt","a");
    while(n<40000){
        if(n<10000)
            n*=10;
        else n*=2;
        int *a=malloc(sizeof(int)*n);
        for(int i=0;i<n;i++)
            *(a+i)=n-i;
        c=selectionSort(a,n);
        fprintf(fptr,"%d\t%d\n",n,c);
    }
    fclose(fptr);
}