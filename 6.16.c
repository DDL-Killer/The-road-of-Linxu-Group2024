#include<stdio.h>
int main(){
    double da,de;
    da=de=100.0;
    int count=0;
    do
    {
        da+=10;
        de*=1.05;
        count++;
    } while (de<=da);
    printf("%.1lf  %.1lf  %d",da,de,count);
    
}
