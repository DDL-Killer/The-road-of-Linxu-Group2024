#include<stdio.h>
#define bu 2
#define lei 0.98
int main(){
    double s;
    scanf("%lf",&s);
    double sum=bu;
    double buu=bu;
    int count=1;
    while (sum<s)
    {
        buu*=lei;
        count++;
        sum+=buu;
    }
    printf("%d",count);
    
}