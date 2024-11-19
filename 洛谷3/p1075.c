#include<stdio.h>
#include<math.h>
int zhishu(int a){
    if(a<2) return 0;
    else if(a==2) return 1;
    else if(a%2==0) return 0;
    else{
        for(int i =3;i<=sqrt(a);i++){
            if(a%i==0){
                return 0;
            }
        }
        return 1;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 2;i<=n;i++){
        if(n%i==0){
            if(zhishu(n/i)&&zhishu(i)){
                printf("%d",n/i);
                return 0;
            }
        }
        
    }
    
}