#include<stdio.h>
double min(double x,double y){
    if(x<y) return x;
    else return y;
}
void chline(char ch,int i,int j){
    for(int row=0;row<j;row++){
        for(int line=0;line<i;line++){
            printf("%c",ch);
        }
        printf("\n");
    }
}
double pinjun(double a,double b){
    if(a!=0&&b!=0){
        double a1=1/a;
        double b1=1/b;
        double res=1/((a1+b1)/2);
        return res;
    }else return 0;

}
int main(){
    double a=1009.9,b=2888.3;
    printf("%lf",min(a,b));
    char ch=';';
    chline(ch,12,12);
    printf("%lf",pinjun(a,b));

}