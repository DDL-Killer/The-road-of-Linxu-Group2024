#include<stdio.h>
#include<stdlib.h>
int main(){
    int num;
    scanf("%d",&num);
    int aa[num][3];
    int sum[num];
    for(int i = 0 ; i<num;i++){
        scanf("%d %d %d",&aa[i][0],&aa[i][1],&aa[i][2]);
    }
    int count=0;
    for(int i = 0; i<num;i++){
        sum[i]=aa[i][0]+aa[i][1]+aa[i][2];
    }
    for(int i = 0;i<num;i++){
        for(int j=i+1;j<num;j++){
            if((abs((sum[i]-sum[j]))<=10)&&(abs((aa[i][0]-aa[j][0]))<=5)&&(abs((aa[i][1]-aa[j][1]))<=5)&&(abs((aa[i][2]-aa[j][2]))<=5)){
                count++;
            }
        }
    }
    printf("%d",count);

}