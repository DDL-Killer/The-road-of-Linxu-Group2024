#include<stdio.h>
int max(int a,int b){
    if(a>b) return a;
    else return b;
}
int main(){
    int a=0;
    int b=0;
    scanf("%d %d",&a,&b);
    int res=max(a,b);
    printf("%d",res);
}