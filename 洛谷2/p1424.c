#include<stdio.h>
#define swim 250
int main(){
    int weekday,day,haveswum,num,yu;
    haveswum=0;
    scanf("%d %d",&weekday,&day);
        if(weekday==6){
            if(day<=2){
                printf("0");
                return 0;
            }
                day-=2;
                weekday=1;
        }else if(weekday==7){
            if(day==1){
                printf("0");
                return 0;
            }
                day-=1;
                weekday=1;
        }
        if(day<=(6-weekday)){
            haveswum=day * swim;
            printf("%d",haveswum);
            return 0;
        }else{
            haveswum=(6-weekday)*swim;
            day-=(8-weekday);
        }
    num=day/7;
    yu=day%7;
    if(yu==6){
        yu=5;
    }
    printf("%d",haveswum+(yu+num*5)*swim);
}