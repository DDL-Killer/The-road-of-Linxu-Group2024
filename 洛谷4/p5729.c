#include<stdio.h>
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int v;
    v=a*b*c;
    int jihang;
    scanf("%d",&jihang);
    int v1;
    int a1,b1,c1,a2,b2,c2;
    int aa,bb,cc;
    int vvv[a][b][c];
        for(int i = 1;i<=a;i++){
            for(int j = 1;j<=b;j++){
                for(int z = 1;z<=c;z++){
                    vvv[i-1][j-1][z-1]=1;
                }
            }
        }
    for(int x = 0;x<jihang;x++){
        scanf("%d %d %d %d %d %d",&a1,&b1,&c1,&a2,&b2,&c2);
        for(int i = a1;i<=a2;i++){
            for(int j = b1;j<=b2;j++){
                for(int z = c1;z<=c2;z++){
                    vvv[i-1][j-1][z-1]=0;
                }
            }
        }
    }
    int sum=0;
        for(int i = 1;i<=a;i++){
            for(int j = 1;j<=b;j++){
                for(int z = 1;z<=c;z++){
                    sum+=vvv[i-1][j-1][z-1];
                }
            }
        }
    printf("%d",sum);
}