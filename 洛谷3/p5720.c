#include<stdio.h>
int main(){
    int day=1;
    int a;
    scanf("%d",&a);
    while(a!=1){
        day++;
        a/=2;
    }
    printf("%d",day);
}