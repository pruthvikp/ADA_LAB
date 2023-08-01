#include<stdio.h>
#include<stdlib.h>

int H[20],n,size;
int heapify(){
    for(int i=n/2;i>=1;i--){
        int pi=i,PV=H[pi],heap=0;
        while(!heap && 2*pi<=n){
            int ci=2*pi;
            if(ci<n)
                if(H[ci+1]>H[ci])
                    ci=ci+1;
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

void sinkdown(){
    int pi=1,PV=H[1],heap=0;
    while(!heap && 2*pi<=n){
        int ci=2*pi;
        if(ci<n)
            if(H[ci+1]>H[ci])
                ci=ci+1;
        if(PV>H[ci])
            heap=1;
        else{
            H[pi]=H[ci];
            pi=ci;
        }
    }
    H[pi]=PV;
}

void heapsort(){
    for(int i=0;i<size;i++){
        int temp = H[1];
        H[1] = H[n];
        H[n] = temp;
        n=n-1;
        sinkdown();
    }
}

void main(){
    printf("Enter n:");
    scanf("%d",&n);
    size=n;
    printf("Enter elements:\n");
    for(int i=1;i<=size;i++)
        scanf("%d",&H[i]);
    heapify();
    for(int i=1;i<=size;i++)
        printf("%d\t",H[i]);
    printf("\n");
    heapsort();
    for(int i=1;i<=size;i++)
        printf("%d\t",H[i]);
    printf("\n");
}
