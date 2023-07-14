#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int c;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int *a,int l,int r){
    int p=a[l],i=l+1,j=r;
    while(i<=j){
        c++;
        while(i<=r && a[i]<p){
            i++;
            c++;
        }
        c++;
        // if(i>r) c--;
        while(j>=i && a[j]>p){
            j--;
            c++;
        }
        if(i<=j){
            swap(&a[i],&a[j]);
            i++;
            j--;
        }
    }
    swap(&a[j],&a[l]);    
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
    int n=1,x=2,i,*b,*w;
    FILE *fptr;
    fptr=fopen("quicksortdata.txt","a");
    while(x<15){
        n=pow(2,x++);
        b=(int *)malloc(sizeof(int)*n);
        w=(int *)malloc(sizeof(int)*n);
        for(i=0;i<n;i++){
            b[i]=10;
            w[i]=i;
        }
        //BEST CASE
        c=0;
        quickSort(b,0,i-1);
        fprintf(fptr,"%d\t%d\t",n,c);
        //WORST CASE
        c=0;
        quickSort(w,0,i-1);
        fprintf(fptr,"%d\n",c);
    }
    fclose(fptr);
}
