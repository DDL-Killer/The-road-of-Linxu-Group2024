#include<stdio.h>
#include<stdlib.h>
int shengxu(const void*a,const void*b){
    return *(int *)a-*(int *)b;
}
void pingjun(float *pingjunshu,int *yuanfen,int jige,int *j){
    qsort(yuanfen,jige,sizeof(int),shengxu);
    float fen=0;
    for(int i = 1;i<jige-1;i++){
        fen+=yuanfen[i];
    }
    fen/=(jige-2);
    pingjunshu[(*j)++]=fen;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int yuan[n][m];
    float pingjunshu[n];
    if(m<=2){
        return 0;
    }
    int z=0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            scanf("%d",&yuan[i][j]);
        }
        pingjun(pingjunshu,yuan[i],m,&z);
    }
    qsort(pingjunshu,z,sizeof(float),shengxu);
    printf("%.2f",pingjunshu[z-1]);
}