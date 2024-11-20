#include<stdio.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int shu[a];
    for(int i = 0;i<a;i++){
        scanf("%d",&shu[i]);
    }
    int min=100000000;
    int temp=0;
    for(int i = 0;i<=a-b;i++){
        for(int j = i;j<b+i;j++){
            temp+=shu[j];
        }
        if(temp<min) min=temp;
        temp=0;
    }
    printf("%d",min);
}