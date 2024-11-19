#include<stdio.h>
int main(){
    int n,x,count=0;;
    scanf("%d %d",&n,&x);
    for(int i = 1;i<=n;i++){
        int temp=i;
        while(temp!=0){
            if(temp%10==x){
                count++;
            }
            temp/=10;
        }
    }
    printf("%d",count);
}