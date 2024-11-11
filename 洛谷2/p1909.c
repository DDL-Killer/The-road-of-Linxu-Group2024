#include<stdio.h>
int panduan(int need,int num,int yuan){
    int fenshu,sum;
    if(need%num!=0){
        fenshu=need/num+1;
    }else{
        fenshu=need/num;
    }
    sum=fenshu*yuan;
    return sum;
}
int main(){
    int need;
    int pencil[3][2];
    int money,temp;
    money=10000000;
    scanf("%d",&need);
    for(int i = 0;i <3;i++){
        scanf("%d %d",&pencil[i][0],&pencil[i][1]);
    }
    for(int i = 0;i <3;i++){
        temp=panduan(need,pencil[i][0],pencil[i][1]);
        if(temp<money){
            money=temp;
        }
    }
    printf("%d",money);
}