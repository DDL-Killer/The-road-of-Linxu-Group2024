#include<stdio.h>
int main(){
    double Sn=0;
    int n;
    scanf("%d",&n);
    for(int i=1;i>0;i++){
        double a=1/(double)i;
        Sn+=a;
        if(Sn>(double)n){
            printf("%d",i);
            return 0;
        }
    }
}