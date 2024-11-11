#include<stdio.h>
int panduan(int a){
    if((a%4==0&&a%100!=0)||(a%100==0&&a%400==0)){
        return 1;
    }else{
        return 0;
    }
}
void shuchu(int a,int b){
    if(a==1||a==3||a==5||a==7||a==8||a==10||a==12){
        a=1;
    }else if(a==2){
        a=2;
    }else{
        a=3;
    }
    switch (a)
    {
    case 1:
    printf("31");
        break;
    case 2:
    if(b==0){
        printf("28");
    }else{
        printf("29");
    }
    break;
    case 3:
    printf("30");
    default:
        break;
    }
}
int main(){
    int year,month;
    scanf("%d %d",&year,&month);
    shuchu(month,panduan(year));
    return 0;
}