//2 plots with different range

#include<stdio.h>
#include<stdlib.h>

int insertionSort(int *a, int n){
    int temp,j,count=0;
    for(int i=1;i<n;i++){
        temp=a[i];
        j=i-1;
        count++;
        while(j>=0 && temp<a[j]){
            count++;
            a[j+1]=a[j];
            j=j-1;
        }
        if(j<0)
            count--;
        a[++j]=temp;
    }
    return count;
}

int main(void){
    int c,n=1;
    FILE *fptr;
    fptr=fopen("insertsortdata.txt","a");
    while(n<20000){
        if(n<10000)
            n*=10;
        else n*=2;
        int *a=malloc(sizeof(int)*n);
        for(int i=0;i<n;i++)
            *(a+i)=rand()%20001;
        //AVG CASE
        c=insertionSort(a,n);
        fprintf(fptr,"%d\t%d\t",n,c);
        //BEST CASE
        c=insertionSort(a,n);
        fprintf(fptr,"%d\t",c);
        //WORST CASE
        for(int i=0;i<n;i++)
            *(a+i)=n-i;
        c=insertionSort(a,n);
        fprintf(fptr,"%d\n",c);
    }
    fclose(fptr);
}