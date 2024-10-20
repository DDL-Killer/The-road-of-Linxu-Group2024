#include<stdio.h>
#include<string.h>
int main(){
    char m[20],x[20];
    int mlen,xlen;
    scanf("%s %s",m,x);
    mlen=strlen(m);
    xlen=strlen(x);
    printf("%s %s\n",m,x);
    printf("%*d %*d\n",mlen,mlen,xlen,xlen);
    printf("%s %s\n",m,x);
    printf("%-*d %-*d\n",mlen,mlen,xlen,xlen);
}