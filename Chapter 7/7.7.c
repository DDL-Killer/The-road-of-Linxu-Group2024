#include<stdio.h>
#define ji 1000
int main(){
    int hour,sum;
    float shui,jin;
    scanf("%d",&hour);
    if(hour<=40&&hour>0){
        sum=hour*ji;
        shui=300*0.15+150*0.2+(sum-450)*0.25;
        jin=(float)sum-shui;
    }
    else if(hour>40){
        sum = 40 * ji+(hour-40)*1.5*ji;
        shui=300*0.15+150*0.2+(sum-450)*0.25;
        jin=(float)sum-shui;
    }
    else{
        printf("wrong!");
        return 0;
    }
    printf("you earn sum is %d ,shui is %.1f ,you can get %.1f",sum,shui,jin);
}