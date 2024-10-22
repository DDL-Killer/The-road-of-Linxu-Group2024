#include<stdio.h>
#define one 8.75
#define two 9.33
#define three 10.00
#define four 11.20
int main(){
    int xuhao,hour,sum;
    float shui,jin,money;
    while (1)
    {
    printf("Enter the number corresponding to the desire pay rate or action:\n\
    1)$8.75/hr   2)$9.33/hr\n\
    3)$10.00/hr  3)$11.20/hr\n\
    5)$quit\n");
    printf("Please input xuhao:");
    scanf("%d",&xuhao);
    switch (xuhao)
    {
    case 1:
        money=one;/* code */
        break;
    case 2:
        money=two;
        break;
    case 3:
        money=three;
        break;
    case 4:
        money=four;
        break;
    case 5:
        return 0;;
    default:
        printf("Please input right num\n");
        continue;
    }
    printf("Please input hour:");
    scanf("%d",&hour);
    if(hour<=40&&hour>0){
        sum=hour*money;
        shui=300*0.15+150*0.2+(sum-450)*0.25;
        jin=(float)sum-shui;
    }
    else if(hour>40){
        sum = 40 * money+(hour-40)*1.5*money;
        shui=300*0.15+150*0.2+(sum-450)*0.25;
        jin=(float)sum-shui;
    }
    else{
        printf("wrong!");
        return 0;
    }
    printf("you earn sum is %d ,shui is %.1f ,you can get %.1f\n\n",sum,shui,jin);
    }
    

    
}