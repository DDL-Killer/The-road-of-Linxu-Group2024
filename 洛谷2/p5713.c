#include<stdio.h>
int main(){
    int local,luogu,num;
    scanf("%d",&num);
    local=5*num;
    luogu=11+3*num;
    if(local>luogu){
        printf("Luogu");
    }else{
        printf("Local");
    }
    return 0;
}