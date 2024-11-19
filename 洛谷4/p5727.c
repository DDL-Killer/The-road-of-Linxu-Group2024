#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[10000];
    a[0]=n;
    int count=0;
    if(n==1){
        printf("1");
        return 0;
    }
    for(int i = 1 ; i <10000;i++){
        if(n%2!=0){
            n=n*3+1;
        }else{
            n/=2;
        }
        a[i]=n;
        count=i;
        if(n==1){
            break;
        }
    }
    for(;count>=0;count--){
        printf("%d",a[count]);
        if(count!=0){
            printf(" ");
        }
    }
}