#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stringMatching(char text[],char pattern[],int m,int n){
    int i,j;
    for(i=0;i<=n-m;i++){
        j=0;
        while(j<m && text[j+i]==pattern[j])
            j+=1;
        if(j==m)
            return i;
    }
    return -1;
}

void main(){
    int n,m,i;
    char text[20],pattern[20];
    printf("Enter the text: ");
    scanf("%s",text);
    printf("Enter the pattern: ");
    scanf("%s",pattern);
    n=strlen(text);
    m=strlen(pattern);
    i=stringMatching(text,pattern,m,n);
    if(i==-1)
        printf("Pattern not found\n");
    else
        printf("Pattern found at index %d\n",i);
}