#include<stdio.h>
#include<stdlib.h>

int sequentialSearch(int a[],int n,int val){
    int count=0;
    for(int i=0;i<n;i++){
        count++;
        if(a[i]==val){
            return count;
        }
    }
    return count;
}

void main(){
    int n=1,c;
    FILE *fptr;
    fptr=fopen("seqsearchdata.txt","a");
    while(n<=40000){
        if(n<10000)
            n=n*10;
        else n=n*2;
        int *a=(int*)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++){
            *(a+i)=(rand()%40001);
        }
        //BEST CASE
        c=sequentialSearch(a,n,*(a+0));
        fprintf(fptr,"%d\t%d\t",n,c);
        //AVG CASE
        c=sequentialSearch(a,n,*(a+(n/2)));
        fprintf(fptr,"%d\t",c);
        //WORST CASE
        c=sequentialSearch(a,n,50000);
        fprintf(fptr,"%d\n",c);
    }
    fclose(fptr);
}
