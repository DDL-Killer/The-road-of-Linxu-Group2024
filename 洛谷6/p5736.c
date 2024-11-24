#include<stdio.h>
#include<math.h>
int sushu(int a){
    if(a<2) return 0;
    else if(a==2) return 1;
    else if(a%2==0) return 0;
    else{
        for(int i = 3;i<=sqrt(a);i++){
            if(a%i==0){
                return 0;
            }
        }
        return 1;
    }
}
int main(){
    int num;
    scanf("%d",&num);
    int n[num];
    for(int i = 0;i<num;i++){
        scanf("%d",&n[i]);
    }
    int tou=0;
    for(int i = 0;i<num;i++){
        if(sushu(n[i])){
        if(tou){
            printf(" ");
        }
            printf("%d",n[i]);
            tou=1;
        }
    }
}