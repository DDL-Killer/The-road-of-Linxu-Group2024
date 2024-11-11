#include<stdio.h>
int main(){
    int date[7][2];
    for(int i=0;i<7;i++){
        scanf("%d %d",&date[i][0],&date[i][1]);
    }
    int sum,day,hour,panduan;
            panduan=hour=0;
    for(int i=0;i<7;i++){
        sum=date[i][0]+date[i][1];

        if(sum>8&&sum>hour){
            hour=sum;
            day=i+1;
            panduan=1;
        }
        if(!panduan){
            day=0;
        }
    }
    printf("%d",day);
}