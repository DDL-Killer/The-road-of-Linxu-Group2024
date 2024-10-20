#include<stdio.h>
int main(){
    int num,end;
    scanf("%d",&num);
    end=num+10;
    while(num<=end){
        printf("%2d ",num++);
    }
    return 0;

}