#include<stdio.h>
#define Single 17850
#define house 23900
#define M_j 29750
#define M_d 14875
void shuishou(int n,int biaozhun){
    float shuijin;
    if(n<biaozhun){
        shuijin=(float)n*biaozhun;
    }
    else{
        shuijin=biaozhun*0.15+(float)(n-biaozhun)*0.28;
    }
    printf("you need %.2f \n\n",shuijin);
}
int main(){
    int biaozhun,type,shouru;
    while (1)
    {
        printf("Please input type:\n1==Single;2==house;3==M_j;4==M_d;5==End\n");
        scanf("%d",&type);
        switch (type)
        {
        case 1:
            biaozhun=Single;
            break;
        case 2:
            biaozhun=house;
            break;
        case 3:
            biaozhun=M_j;
            break;
        case 4:
            biaozhun=M_d;
            break;
        case 5:
            return 0;
        default:
            printf("Please input right type\n\n");
            continue;
        }
    printf("Please input your input:");
    scanf("%d",&shouru);
    shuishou(shouru,biaozhun);
    }
}