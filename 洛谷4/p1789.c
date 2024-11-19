#include<stdio.h>
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int fanwei[n+4][n+4];
    for(int i =0;i<n+4;i++){
        for(int j =0 ;j<n+4;j++){
            fanwei[i][j]=1;
        }
    }
    int huo[m][2];
    for(int i = 0;i<m;i++){
        scanf("%d %d",&huo[i][0],&huo[i][1]);
    }
    if(k>0){
    int yin[k][2];
    
    for(int j = 0;j<k;j++){
        scanf("%d %d",&yin[j][0],&yin[j][1]);
    }
    
    for(int j = 0;j<k;j++){
        int a,b;
        a=yin[j][0];
        b=yin[j][1];
        fanwei[a-1][b-1]=fanwei[a-1][b]=fanwei[a-1][b+1]=fanwei[a-1][b+2]=fanwei[a-1][b+3]=fanwei[a][b-1]=fanwei[a][b]=fanwei[a][b+1]=fanwei[a][b+2]=fanwei[a][b+3]=fanwei[a+1][b-1]=fanwei[a+1][b]=fanwei[a+1][b+1]=fanwei[a+1][b+2]=fanwei[a+1][b+3]=fanwei[a+2][b-1]=fanwei[a+2][b]=fanwei[a+2][b+1]=fanwei[a+2][b+2]=fanwei[a+2][b+3]=fanwei[a+3][b-1]=fanwei[a+3][b]=fanwei[a+3][b+1]=fanwei[a+3][b+2]=fanwei[a+3][b+3]=0;
    }}
        for(int i = 0;i<m;i++){
        int a,b;
        a=huo[i][0];
        b=huo[i][1];
        fanwei[a-1][b+1]=fanwei[a][b]=fanwei[a][b+1]=fanwei[a][b+2]=fanwei[a+1][b-1]=fanwei[a+1][b]=fanwei[a+1][b+1]=fanwei[a+1][b+2]=fanwei[a+1][b+3]=fanwei[a+2][b]=fanwei[a+2][b+1]=fanwei[a+2][b+2]=fanwei[a+3][b+1]=0;
    }
    int sum=0;
    for(int i =2;i<n+2;i++){
        for(int j = 2;j<n+2;j++){
            sum+=fanwei[i][j];
        }
    }
    printf("%d",sum);

}