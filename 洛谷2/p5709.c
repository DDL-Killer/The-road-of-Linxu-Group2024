#include<stdio.h>
int main(){
    int m,t,s;
    scanf("%d %d %d",&m,&t,&s);
    if(t==0){
        printf("0");
        return 0;
    }
    else if(s<t){
        printf("%d",m);
        return 0;
    }
    int num;
    num=m-s/t;
    if(num<0){
        printf("0");
        return 0;
    }
    else{
        if(s%t==0){
            printf("%d",num);
        }
        else{
            printf("%d",num-1);
        }
    }
    return 0;
}