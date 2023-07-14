#include<stdio.h>
#include<stdlib.h>

int H[20],n;
int heap(){
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

void main(){
    printf("Enter n:");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for(int i=1;i<=n;i++)
        scanf("%d",&H[i]);
    heap();
    for(int i=1;i<=n;i++)
        printf("%d\t",H[i]);
}