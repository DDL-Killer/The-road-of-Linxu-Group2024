#include<stdio.h>
int main(){
    char a;
    int oushu,jishu;
    double pingjuno,pingjunj;
    pingjunj=pingjuno=0;
    oushu=jishu=0;
    while ((a=getchar())!='0')
    {
        if(a!='\n'){
            if(a%2==0){
                oushu++;
                pingjuno=(a+pingjuno)/(double)oushu;
            }
            else{
                jishu++;
                pingjunj=(a+pingjunj)/(double)jishu;
            }
        }
    }
    printf("The number of oushu is %d ,average is %.2lf\n",oushu,pingjuno);
    printf("The number of jishu is %d ,average is %.2lf\n",jishu,pingjunj);
}