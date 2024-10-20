#include<stdio.h>
int main(){
    int day;
    scanf("%d",&day);
    int w,d;
    w=day/7;
    d=day%7;
    printf("%d days are %d weeks, %d days",day,w,d);
    return 0;
}