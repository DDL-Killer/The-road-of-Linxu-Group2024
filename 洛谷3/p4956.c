#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int x,k;
    int sum=n/52;
    for(int i = 100;i>=1;i--){
        for(int j =1;j<=100;j++){
            if(7*i+21*j==sum){
                printf("%d\n%d",i,j);
                return 0;
            }
        }
    }
}