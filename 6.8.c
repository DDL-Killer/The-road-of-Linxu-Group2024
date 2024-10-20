#include<stdio.h>
int main(){
    float a,b;
    int c=scanf("%f %f",&a,&b);
    while (c==2)
    {
        float res=(a-b)/(a*b);
        printf("%.2f",res);
        c=scanf("%f %f",&a,&b);
    }
    
}