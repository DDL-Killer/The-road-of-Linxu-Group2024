#include<stdio.h>
#include<math.h>
int zhishu(int a){
    if(a<2) return 0;
    else if(a==2) return 1;
    else if(a%2==0) return 0;
    else{
        for(int i = 3;i<=sqrt(a);i++){
            if(a%i==0){
                return 0;
            }
        }
        return 1;
    }
}
int main(){
    int L;
    scanf("%d",&L);
    if(L<2){
        printf("0");
        return 0;
    }else if(L==2){
        printf("2\n1");
        return 0;
    }else{
        printf("2\n");
    }
    int sum=2;
    int count=1;
    int i=3;
    while(1)
    {
        if(zhishu(i)){
            if(sum+i>L){
                printf("%d",count);
                return 0;
            }
            sum+=i;
            count ++;
            printf("%d\n",i);
        }
        i+=2;
    }
    return 0;
}