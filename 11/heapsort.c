#include<stdio.h>
#include<stdlib.h>

int H[20000],n=1,size=1,c=0;

int heap(){
    for(int i=n/2;i>=1;i--){
        int pi=i,PV=H[pi],heap=0,ci;
        while(!heap && 2*pi<=n){
            ci=2*pi;
            if(ci<n){
                c++;
                if(H[ci+1]>H[ci])
                    ci=ci+1;
            }
            c++;
            if(PV>H[ci])
                heap=1;
            else{
                H[pi]=H[ci];
                pi=ci;
            }
        }
        H[pi]=PV;
    }
}

void heapify(){
    int pi=1,PV=H[1],heap=0;
    while(!heap && 2*pi<=n){
        int ci=2*pi;
        if(ci<n){
            c++;
            if(H[ci+1]>H[ci])
                ci=ci+1;
        }
        c++;
        if(PV>H[ci])
            heap=1;
        else{
            H[pi]=H[ci];
            pi=ci;
        }
    }
    H[pi]=PV;
}

void heapSort(){
    for(int i=0;i<size;i++){
        int temp = H[1];
        H[1] = H[n];
        H[n] = temp;
        n=n-1;
        heapify();
    }
}

void main(){
    FILE *fptr;
    fptr=fopen("heapsortdata.txt","a");
    // while(size<=100){
    //     size+=10;
    while(size<20000){
        if(size<10000)
            size=size*10;
        else size*=2;
        for(int i=0;i<size;i++)
            H[i]=size-i;
        //BEST CASE
        c=0;
        n=size;
        heap();
        heapSort();
        fprintf(fptr,"%d\t%d\t",size,c);
        //WORST CASE
        c=0;
        n=size;
        heap();
        heapSort();
        fprintf(fptr,"%d\n",c);
    }
    fclose(fptr);
}
