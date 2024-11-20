#include<stdio.h>
#include<stdbool.h>
int main(){
    int num;
    scanf("%d",&num);
    int nb[num];
    for(int i =0;i<num;i++){
        scanf("%d",&nb[i]);
    }
    bool found[10000001]={0};
    int res=0;
    for(int i = 0 ; i< num;i++){
        for(int j = i+1;j<num;j++){
            int sum=nb[i]+nb[j];
            if(found[sum]) continue;
            for(int z=0;z<num;z++){
                if(nb[z]==sum&&nb[z]!=nb[i]&&nb[z]!=nb[j]){
                    res++;
                    found[sum]= 1;
                    break;
                }
            }
        }
    }
    printf("%d",res);
}