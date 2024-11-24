#include<stdio.h>
#include<math.h>

int zhishu(int a){
    if(a<2) return 0;
    else if(a==2) return 1;
    else if(a%2==0) return 0;
    else{
        for(int i = 3;i<=sqrt(a);i++){
            if(a%i==0) return 0;
        }
        return 1;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i =4;i<=n;i+=2){
        for(int j = 2;j<i;j++){
            if(zhishu(j)&&zhishu(i-j)){
                printf("%d=%d+%d\n",i,j,i-j);
                break;
            }
        }
    }

}