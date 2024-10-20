#include<stdio.h>
int main(){
    int fs=5;
    int count=1;
    do
    {
        fs-=count;
        fs*=2;
        count++;
        printf("%d\n",fs);
    } while (fs<150);
    printf("%d",count);
}