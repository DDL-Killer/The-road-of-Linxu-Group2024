#include<stdio.h>
#define one 0.4463
#define onemax 66.945
#define two 0.4663
#define twomax 183.52
#define three 0.5663
int main(){
    int a,b;
    scanf("%d",&a);
    if(a<=150){
        b=1;
    }
    else if(a>=151&&a<=400){
        b=2;
    }
    else{
        b=3;
    }
    switch (b)
    {
    case 1:
        printf("%.1f",(float)a*one);
        break;
    case 2:
        printf("%.1f",onemax+(float)(a-150)*two);
        break;
    case 3:
        printf("%.1f",twomax+(float)(a-400)*three);
        break;
    default:
        break;
    }
}