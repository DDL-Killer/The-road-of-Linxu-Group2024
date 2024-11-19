#include<stdio.h>
int main(){
    int yu[12];
    int cun[12]={0};
    int shou[12];
    int sheng=0;
    for(int i = 0;i<12;i++){
       scanf("%d",&yu[i]);
       shou[i]=300;
    }
    for(int i=0;i<12;i++){
        if(i>0){
            shou[i]+=sheng;
        }
        sheng=shou[i]-yu[i];
        if(sheng>=100){
            cun[i]=sheng/100*100;
            sheng%=100;
        } if(sheng<0){
            printf("-%d",i+1);
            return 0;
        }
    }
    int sum=0;
    for(int j = 0 ; j < 12;j++){
        sum+=cun[j];
    }
    printf("%.0lf",sum*1.2+sheng);
}