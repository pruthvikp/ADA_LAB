#include<stdio.h>
#include<stdlib.h>

int string(int *t, int *p,int m){
    int c=0;
    for(int i=0;i<=10-m;i++){
        int j=0;
        c++;
        while(j<m && t[j+i]==p[j]){
            c++;
            j=j+1;
        }
        if(j==m)
            return c;
    }
    return c;
}

void main(){
    int *w,*b,*t,count;
    FILE *fptr;
    t=(int*)malloc(10*sizeof(int));
    for(int i=0;i<10;i++)
        t[i]='a';
    fptr=fopen("stringdata.c","a");
    for(int i=2;i<10;i++){
        w=(int*)malloc(sizeof(int)*i);
        b=(int*)malloc(sizeof(int)*i);
        for(int j=0;j<i;j++){
            b[j]='a';
            if(j!=i-1)
                w[j]='a';
            else
                w[j]='b';
        }
        //BEST CASE
        count=string(t,b,i);
        fprintf(fptr,"%d\t%d\t",i,count);
        //WORST CASE
        count=string(t,w,i);
        fprintf(fptr,"%d\n",count);
    }
    fclose(fptr);
}
