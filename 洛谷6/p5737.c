#include<stdio.h>
int runnian(int *count,int year,int *num,int *jishu){
    if((year%4==0&&year%100!=0)||(year%400==0)){
        (*count)++;
        num[*jishu]=year;
        (*jishu)++;
    }
}
int main(){
    int year1,year2;
    scanf("%d %d",&year1,&year2);
    int sum=0;
    int i = 0;
    int nian[2000];
    for(int j = year1;j<=year2;j++){
        runnian(&sum,j,nian,&i);
    }
    printf("%d\n",sum);
    for(int j = 0;j<i;j++){
        if(j!=0){
            printf(" ");
        }
        printf("%d",nian[j]);
    }
}