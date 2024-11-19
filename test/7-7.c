#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    int count=0;
    if(num==0){
        printf("32");
        return 0;
    }
    if(num<0){
        printf("0");
        return 0;
    }
    while (1)
    {
        num/=2;
        count++;
        if(num==0){
            printf("%d",32-count);
            return 0;}
    }   
}