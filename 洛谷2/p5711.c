#include<stdio.h>
int main(){
    int year,panduan1,panduan2;
    panduan1=panduan2=0;
    scanf("%d",&year);
    if(year%4==0&&year%100!=0){
        panduan1=1;
    }
    if(year%100==0&&year%400==0){
        panduan2=1;
    }
    if(panduan1||panduan2){
        printf("1");
    }
    else if(!panduan1&&!panduan2){
        printf("0");
    }
    return 0;
}