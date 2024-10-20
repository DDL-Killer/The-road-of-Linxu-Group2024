#include<stdio.h>
int main(){
    double a=100.0;
    int count = 0;
    do
    {
        count++;
        a*=1.08;
        a-=10;
    } while (a>9.2593);
    printf("%d",count);
    
}