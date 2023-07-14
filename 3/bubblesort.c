#include<stdio.h>
#include<stdlib.h>

int bubbleSort(int *a,int n){
    int c=0,i,j,temp;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++){
            c++;
            if(*(a+j)>*(a+j+1)){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    return c;
}

int main(void){
    int c,n=1;
    FILE *fptr;
    fptr=fopen("bubblesortdata.txt","a");
    while(n<20000){
        if(n<10000)
            n*=10;
        else n*=2;
        int *a=malloc(sizeof(int)*n);
        for(int i=0;i<n;i++)
            *(a+i)=rand()%40001;
        //AVG CASE
        c=bubbleSort(a,n);
        fprintf(fptr,"%d\t%d\t",n,c);
        //BEST CASE
        c=bubbleSort(a,n);
        fprintf(fptr,"%d\t",c);
        //WORST CASE
        for(int i=0;i<n;i++)
            *(a+i)=n-i;
        c=bubbleSort(a,n);
        fprintf(fptr,"%d\n",c);
    }
    fclose(fptr);
}
