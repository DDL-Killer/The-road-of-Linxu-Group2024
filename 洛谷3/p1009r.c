#include<stdio.h>
#define max 200
void jiecheng(int n,int *fact){
    fact[0]=1;
    int len=1;
    for(int i=2;i<=n;i++){
        int carry=0;
        for(int j=0;j<len;j++){
            int temp=fact[j]*i+carry;
            carry=temp/10;
            fact[j]=temp%10;
        }
        while(carry){
            fact[len++]=carry%10;
            carry/=10;
        }
    }
}
void leijia(int *res,int*fact,int len){
   int carry=0;
   for(int i=0;i<len||carry;i++){
    if(i==len){
        res[i]=fact[i]+carry;
        len++;
    }else{
        res[i]+=fact[i]+carry;
    }
    carry=res[i]/10;
    res[i]%=10;
   }
    
}
int main(){
    int n;
    scanf("%d",&n);
    int fact[max]={0};
    int res[max]={0};
    for(int i=1;i<=n;i++){
        jiecheng(i,fact);
        leijia(res,fact,max);
    }
    int count=max-1;
    while(count>=0&&res[count]==0){
        count--;
    }
    for(;count>=0;count--){
        printf("%d",res[count]);
    }
    return 0;
}