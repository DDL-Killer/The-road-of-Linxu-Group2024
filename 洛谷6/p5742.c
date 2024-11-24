#include<stdio.h>
typedef struct{
    int xh;
    int xycj;
    int stcj;
    int sum;
}pdj;
int zh(int a,int b){
    int zh=a*7+b*3;
    return zh;
}
int main(){
    int n;
    scanf("%d",&n);
    pdj pdjs[n];
    for(int i = 0;i<n;i++){
        scanf("%d %d %d",&pdjs[i].xh,&pdjs[i].xycj,&pdjs[i].stcj);
        pdjs[i].sum=pdjs[i].xycj+pdjs[i].stcj;
    }
    for(int i = 0;i<n;i++){
        if(pdjs[i].sum>140&&zh(pdjs[i].xycj,pdjs[i].stcj)>=800){
            printf("Excellent\n");
        }else{
            printf("Not excellent\n");
        }
    }
}