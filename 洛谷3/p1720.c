#include<math.h>
#include<stdio.h>
int main(){
    double n;
    scanf("%lf",&n);
    double a=pow((double)((1+sqrt(5))/2),n);
    double b=pow((double)((1-sqrt(5))/2),n);
    double fenzi=a-b;
    double fn=fenzi/(sqrt(5));
    printf("%.2lf",fn);
}
