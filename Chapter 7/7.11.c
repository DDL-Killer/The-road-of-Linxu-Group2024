#include<stdio.h>
#define Yangji 2.05
#define Tiancai 1.15
#define Carrot 1.09
int main(){
    int pY,pT,pC,huancun,sump,panduan;
    char type;
    double allcost,sumf,Yf,youhui,yunfee,Tf,Cf;
    pY=pT=pC=huancun=0;
    youhui=0.95;
    panduan=1;
    printf("Yangji:2.05p/$     Tiancai:1.15p/$     Carrot:1.09p/$\n");
    printf("Choose your type:\na = Yangji\nb = Tiancai\nc = Carrot\nq = quit\n");
    while (panduan)
    {
        scanf(" %c",&type);
        switch (type)
        {
        case 'a':
            printf("Please input pound:");
            scanf("%d",&huancun);
            pY+=huancun;
            huancun=0;
            break;
        case 'b':
            printf("Please input pound:");
            scanf("%d",&huancun);
            pT+=huancun;
            huancun=0;
            break;
        case 'c':
            printf("Please input pound:");
            scanf("%d",&huancun);
            pC+=huancun;
            huancun=0;
            break;
        case 'q':
            panduan=0;
            break;
        default:
            printf("Please input right type\n");
            break;
        }
    }
    sump=pC+pT+pY;
    Cf=(double)pC*Carrot;
    Tf=Tiancai*(double)pT;
    Yf=(double)pY*Yangji;
    sumf=Tf+Cf+Yf;
    if(sumf>100){
        sumf*=youhui;
    }
    if(sump<=5){
        yunfee=6.5;
    }
    else if(sump>5&&sump<=20){
        yunfee=14;
    }
    else{
        yunfee=14+(sump-14)*0.5;
    }
    allcost=sumf+yunfee;
printf("Yangji:2.05p/$     Tiancai:1.15p/$     Carrot:1.09p/$\n");
printf("You have bought %d pound Yangji, cost %.2lf\n", pY, Yf);
printf("You have bought %d pound Tiancai, cost %.2lf\n", pT, Tf);
printf("You have bought %d pound Carrot, cost %.2lf\n", pC, Cf);
printf("Total pounds of vegetable: %d, total cost: %.2lf\n", sump, sumf);
printf("Shipping cost: %.2lf, total amount to pay: %.2lf\n", yunfee, allcost);


    
}