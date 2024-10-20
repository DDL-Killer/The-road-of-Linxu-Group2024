#include<stdio.h>
int main(){
    double a[8];
    double b[8];

    for(int i=0;i<8;i++){
        scanf("%lf",&a[i]);
        b[i]=a[i];
        if(i>0){
            b[i]=b[i-1]+a[i];
        }
    }
    for(int i=0;i<8;i++){
        printf("%5.1lf ",a[i]);
    }
    printf("\n");
    for(int i=0;i<8;i++){
        printf("%5.1lf ",b[i]);
    }
}