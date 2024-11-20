#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    int nb[N][N];
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            nb[i][j]=0;
        }
    }
    int cun[N*N][2];
    cun[0][0]=0;
    cun[0][1]=N/2;
    nb[0][N/2]=1;
    for(int i = 1;i<N*N;i++){
        int a=cun[i-1][0];
        int b=cun[i-1][1];
        if(a==0&&b!=N-1){
            cun[i][0]=N-1;
            cun[i][1]=cun[i-1][1]+1;
        }else if(a!=0&&b==N-1){
            cun[i][0]=cun[i-1][0]-1;
            cun[i][1]=0;
        }else if(a==0&&b==N-1){
            cun[i][0]=cun[i-1][0]+1;
            cun[i][1]=cun[i-1][1];
        }else{
            if(nb[a-1][b+1]==0){
                cun[i][0]=a-1;
                cun[i][1]=b+1;
            }else{
                cun[i][0]=a+1;
                cun[i][1]=b;
            }
        }
        nb[cun[i][0]][cun[i][1]]=i+1;

    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(j!=0){
                printf(" ");
            }
            printf("%d",nb[i][j]);
        }
        printf("\n");
    }
}