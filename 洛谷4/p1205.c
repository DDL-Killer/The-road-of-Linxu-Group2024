#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    char x[num][num];
    for(int i = 0;i<num;i++){
        for(int j=0;j<num;j++){
            scanf(" %c",&x[i][j]);
        }
    }
    char xx[num][num];
    for(int i = 0;i<num;i++){
        for(int j=0;j<num;j++){
            xx[i][j]=x[i][num-1-j];
        }
    }
    char x1[num][num];
    for(int i = 0;i<num;i++){
        for(int j=0;j<num;j++){
            scanf(" %c",&x1[i][j]);
       }
    }
    int pd[7]={1,1,1,1,1,1,1};
    for(int i = 0;i<num;i++){
        for(int j=0;j<num;j++){
            if (x1[i][j] != x[num - 1 - j][i]) { // 旋转90度
                pd[0] = 0;
            }  if (x1[i][j] != x[num - 1 - i][num - 1 - j]) { // 旋转180度
                pd[1] = 0;
            }  if (x1[i][j] != x[j][num - 1 - i]) { // 旋转270度
                pd[2] = 0;
            }  if (x1[i][j] != x[i][num - 1 - j]) { // 水平反射
                pd[3] = 0;
            }  if ((x1[i][j] != xx[num - 1 - j][i]) &&// 水平反射+旋转90度
                       (x1[i][j] != xx[num - 1 - i][num - 1 - j]) && // 水平反射+旋转180度
                       (x1[i][j] != xx[j][num - 1 - i])) { // 水平反射+旋转270度
                pd[4] = 0;
            }  if (x1[i][j] != x[i][j]) { // 不改变
                pd[5] = 0;
            } 

        }}
    for(int i = 0;i<6;i++){
        if(pd[i]==1){
            printf("%d",i+1);
            return 0;
        }
    }
    printf("7");
    return 0;
}