#include<stdio.h>
int jc(int a){
    if(a==1) return a;
    else return a*jc(a-1);
}
int main(){
    int a;
    scanf("%d",&a);
    printf("%d",jc(a));
}