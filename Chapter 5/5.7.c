#include<stdio.h>
void san(double a){
    printf("%lf",a*a*a);
}
int main(){
    double a;
    scanf("%lf",&a);
    san(a);
    return 0;
}