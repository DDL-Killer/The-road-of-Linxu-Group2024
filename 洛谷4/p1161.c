#include<stdio.h>
int nb[2000001]={0};

int main(){
    int a;
    int b;
    double c;
    scanf("%d",&a);
    for(int i = 1;i<=a;i++){
        scanf("%lf %d",&c,&b);
        for(int j = 1;j<=b;j++){
            if(nb[(int)(j*c)]==0){
                nb[(int)(j*c)]=1;
            }else{
                nb[(int)(j*c)]=0;
            }
        }
    }
            for(int i =1;;i++){
            if(nb[i]==1){
                printf("%d",i);
                return 0;
            }
        }
}