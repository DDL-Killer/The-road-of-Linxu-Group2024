#include<stdio.h>
#include<math.h>
#define max 200
void jiecheng(int n,int * fact){
    fact[0]=1;
    int len=1;
    for(int i = 2;i<=n;i++){
        int carry=0;
        for(int j = 0;j<len;j++){
            int temp=fact[j]*i+carry;
            fact[j]=temp%10;
            carry=temp/10;
        }
        while (carry)
        {
            fact[len++]=carry%10;
            carry/=10;
        }
        
    }
}

void leijia(int * res,int * fact,int len){
    int carry = 0;
    for(int i = 0;i<len||carry;i++){
        if(i==len){
            res[i]=fact[i]+carry;
            len++;
        }
        res[i]+=fact[i]+carry;
        carry=res[i]/10;
        res[i]%=10;
    }
}
int zhishu(int a){
    if(a<2) return 0;
    else if(a==2) return 1;
    else if(a%2==0) return 0;
    else{
        for(int i = 3;i<=sqrt(a);i+=2){
            if(a%i==0){
                return 0;
            }
        }
        return 1;
    }
}
int main(){

}