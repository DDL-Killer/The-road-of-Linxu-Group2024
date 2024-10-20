#include<stdio.h>
int main(){
    int a[8];
    for(int i=0;i<8;i++){
        scanf("%d",&a[i]);
    }
    for(int j=7;j>=0;j--){
        printf("%d",a[j]);
    }
}