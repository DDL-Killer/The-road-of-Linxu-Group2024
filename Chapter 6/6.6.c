#include<stdio.h>
int main(){
    int min,max;
    scanf("%d %d",&min,&max);
    for(;min<=max;min++){
        long a=min*min;
        long b=min*min*min;
        printf("%4d    %8ld    %16ld\n",min,a,b);
    }
}