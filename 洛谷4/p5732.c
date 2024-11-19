#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    int nb[a][a];
    for(int i = 0;i<a;i++){
        nb[i][0]=nb[i][i]=1;    
    }
    for(int i = 2;i<a;i++){
        for(int j = 1;j<i;j++){
            nb[i][j]=nb[i-1][j]+nb[i-1][j-1];
        }
    }
    for(int i = 0 ; i<a;i++){
        for(int j = 0;j<i+1;j++){
            printf("%d ",nb[i][j]);
        }
        printf("\n");
    }
}