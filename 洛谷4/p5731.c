#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int aa[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aa[i][j] = 0;  // 初始化为0
        }
    }
    int x,y;
    x=y=0;
    int count = 1;
    while (count<=n*n)
    {
        while (y<n&&aa[x][y]==0)
        {
            aa[x][y]=count++;
            y++;
        }
        y--;
        x++;
        while (x<n&&aa[x][y]==0)
        {
            aa[x][y]=count++;
            x++;
        }
        x--;
        y--;
        while (y>=0&&aa[x][y]==0)
        {
            aa[x][y]=count++;
            y--;
        }
        y++;
        x--;
        while (x>=0&&aa[x][y]==0)
        {
            aa[x][y]=count++;
            x--;
        }
        x++; 
        y++;    
    }
    
    for(int z = 0;z<n;z++){
        for(int q = 0;q<n;q++){
            printf("%3d",aa[z][q]);
        }
        printf("\n");
    }
    
}