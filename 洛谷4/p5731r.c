#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    int nb[a][a];
    for(int i = 0 ; i< a;i++){
        for(int j = 0;j<a;j++){
            nb[i][j]=0;
        }   
    }
    int x,y,count;
    count=1;
    x=y=0;
    while (count<=a*a)
    {
        while (y<a&&nb[x][y]==0)
        {
            nb[x][y]=count++;
            y++;
        }
        y--;
        x++;
        while (x<a&&nb[x][y]==0)
        {
            nb[x][y]=count++;
            x++;
        }
        x--;
        y--;
        while (y>=0&&nb[x][y]==0)
        {
            nb[x][y]=count++;
            y--;
        }
        y++;
        x--;
        while (x>=0&&nb[x][y]==0)
        {
            nb[x][y]=count++;
            x--;
        }
        x++;
        y++;   
    }
    for(int i = 0;i<a;i++){
        for(int j = 0;j<a;j++){
            printf("%3d",nb[i][j]);
        }
        printf("\n");
    }
}