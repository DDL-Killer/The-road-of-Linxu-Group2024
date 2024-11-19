#include<stdio.h>
#define max 100
void jiecheng(int a,int *res){
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
void leijia(int * res,int*num,int len){
    int carry=0;
    for(int i=0;i<len||carry;i++){
        if(i==len){
            res[i]=num[i]+carry;
            len++;
        }else{
            res[i]=num[i]+carry;
        }
        carry=res[i]/10;
        res[i]%=10;
    }
}