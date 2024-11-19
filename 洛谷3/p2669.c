#include<stdio.h>
int main(){
    int k;
    int sum=0;
    int biao=1;
    int count=0;
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        if(count!=biao){
            sum+=biao;
            count++;
        }else{
            biao++;
            count=0;
            sum+=biao;
            count++;
        }
    }
    printf("%d",sum);
}