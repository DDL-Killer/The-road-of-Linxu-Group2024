#include<stdio.h>
#include<math.h>
double jvli(double x1,double y1,double x2,double y2){
    double a=(x2-x1)*(x2-x1);
    double b=(y2-y1)*(y2-y1);
    return sqrt(a+b);
}
int main(){
    double zuobiao[3][2];
    for(int i =0;i<3;i++){
        scanf("%lf %lf",&zuobiao[i][0],&zuobiao[i][1]);
    }
    double c1=jvli(zuobiao[0][0],zuobiao[0][1],zuobiao[1][0],zuobiao[1][1]);
    double c2=jvli(zuobiao[0][0],zuobiao[0][1],zuobiao[2][0],zuobiao[2][1]);
    double c3=jvli(zuobiao[1][0],zuobiao[1][1],zuobiao[2][0],zuobiao[2][1]);
    double sum=c1+c2+c3;
    printf("%.2lf",sum);
}