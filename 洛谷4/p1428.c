#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int jishu=0;
    int aa=1;
    for(int i = 0;i<n;i++){
    for(int j = 0 ; j< i;j++){
        if(a[j]<a[i]){
            jishu++;
        }
        }
        if(i!=0){
            printf(" ");
        }
        printf("%d",jishu);
        jishu=0;
    }
}