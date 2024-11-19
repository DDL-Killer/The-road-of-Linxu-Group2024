#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int max=-66666;
    int xiabiao;
    for(int i = 0;i<n;i++){
        if(a[i]>max){
            max=a[i];
            xiabiao=i;
        }
    }
    printf("%d %d",max,xiabiao);
}