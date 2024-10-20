#include<stdio.h>
int main(){
    int min,max,sum;
    sum = 0;
    printf("Enter lower and upper integer limits:");
    do
    {
        scanf("%d %d",&min,&max);
        if(min>=max){
            printf("Done");
            break;
        }
            int pfmin,pfmax;
            pfmin=min*min;
            pfmax=max*max;
        for(;min<max+1;min++){
            int a = min*min;
            sum+=a;
        }
        printf("The sums of the squares from %d to %d is %d\n",pfmin,pfmax,sum);
        sum = 0;
        printf("Enter next set of limits:");

    } while (1);
    return 0;
}
