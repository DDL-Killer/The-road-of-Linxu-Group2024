#include<stdio.h>
#include<string.h>
int main(){
    char m[40],x[40];
    scanf("%s %s",m,x);
    int xlen,mlen;
    xlen=strlen(x);
    mlen=strlen(m);
    printf("ming is :\"%s\",xing is :\"%s\"\n",m,x);
    printf("ming is :\"%20s\",xing is :\"%20s\"\n",m,x);
    printf("ming is :\"%-20s\",xing is :\"%-20s\"\n",m,x);
    printf("ming is :\"%*s\",xing is :\"%*s\"\n",mlen+3,m,xlen+3,x);
    return 0;
}