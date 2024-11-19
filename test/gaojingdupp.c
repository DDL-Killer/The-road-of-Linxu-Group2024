#include<stdio.h>
#define max 200
int jiecheng(int a,int *res){
    res[0]=1;
    int len=1;
    for(int i = 2;i<=a;i++){
        int carry=0;
        for(int j=0;j<len;j++){
            int temp=res[j]*i+carry;
            res[j]=temp%10;
            carry=temp/10;
        }
        while (carry)
        {
            res[len++]=carry%10;
            carry/=10;
        }
    }
}
int leijia(int *fact,int *res,int len){
    int carry=0;
    for(int i = 0;i<len||carry;i++){
        if(i==len){
            fact[i]=res[i]+carry;
            len++;
        }
        fact[i]+=res[i]+carry;
        carry=fact[i]/10;
        fact[i]%=10;

    }
    
}