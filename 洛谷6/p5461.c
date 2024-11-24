#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    int a;
    scanf("%d",&a);
    int r=pow(2,a);
    int shuzu[r][r];
    memset(shuzu,0,sizeof(shuzu));
    for(int i = 0; i < r; i++) {
        shuzu[i][r-1] = shuzu[i][r-1-i] = 1;
    }
    for(int i = 2; i < r; i++) {
        for(int j = r-2; j >= r-i; j--) {
            if(shuzu[i-1][j] + shuzu[i-1][j+1] == 1) {
                shuzu[i][j] = 1;
        }
    }
}
    for(int i = 0;i<r;i++){
        for(int j = 0;j<r;j++){
            if(j!=0){
                printf(" ");
            }
            printf("%d",shuzu[i][j]);
        }
        printf("\n");
    }
}