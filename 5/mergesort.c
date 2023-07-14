//gcc mergesort.c -lm
    
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int merge(int *a,int beg,int mid,int end,int c){
    int n1=mid-beg+1;
    int n2=end-mid;
    int Larr[n1],Rarr[n2];
    for(int i=0;i<n1;i++)
        Larr[i]=a[beg+i];
    for(int j=0;j<n2;j++)
        Rarr[j]=a[mid+j+1];
    int i=0,j=0,k=beg;
    while(i<n1 && j<n2){
        c=c+1;
        if(Larr[i]<=Rarr[j])
            a[k++]=Larr[i++];
        else 
            a[k++]=Rarr[j++];
    }
    while(i<n1)
        a[k++]=Larr[i++];
    while(j<n2)
        a[k++]=Rarr[j++];   
    return c; 
}

int mergeSort(int *a,int beg,int end,int c){
    if(beg<end){
        int mid=(beg+end)/2;
        c=mergeSort(a,beg,mid,c);
        c=mergeSort(a,mid+1,end,c);
        c=merge(a,beg,mid,end,c);
    }
    return c;
}

int main(){
    int n=1,x=2,*a,c;
    FILE *fptr;
    fptr=fopen("mergesortdata.txt","a");
    while(x<15){
        n=pow(2,x++);
        a=(int*)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++){
            srand(i);
            a[i]=rand()%3000000;
        }
        //AVG CASE
        c=0;
        c=mergeSort(a,0,n-1,c);
        fprintf(fptr,"%d\t%d\t",n,c);
        //BEST CASE
        c=0;
        c=mergeSort(a,0,n-1,c);
        fprintf(fptr,"%d\t",c);
        //WORST CASE
        int i,j,k=1,temp,c=0;
        for(i=0,j=n/2;i<n/2;i++,j++){
            a[i]=k;
            a[j]=k+1;
            k+=2;
        }
        for(i=1,j=n/2-2;i<j;i+=2,j-=2){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        for(i=n/2+1,j=n-2;i<j;i+=2,j-=2){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        c=mergeSort(a,0,n-1,c);
        fprintf(fptr,"%d\n",c);
    }
    fclose(fptr);
}
