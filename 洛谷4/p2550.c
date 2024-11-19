#include<stdio.h>
int main(){
    int jiang[7]={0,0,0,0,0,0,0};
    int num;
    scanf("%d",&num);
    int biao[7];
    scanf("%d %d %d %d %d %d %d",&biao[0],&biao[1],&biao[2],&biao[3],&biao[4],&biao[5],&biao[6]);
    int count;
    count=0;
    int huan[7];
    for(int i = 0;i<num;i++){
        scanf("%d %d %d %d %d %d %d",&huan[0],&huan[1],&huan[2],&huan[3],&huan[4],&huan[5],&huan[6]);
        for(int j = 0;j<7;j++){
            for(int z = 0;z<7;z++){
                if(huan[j]==biao[z]){
                    count++;
                }
            }
        }
            if(count>0){
                jiang[7-count]+=1;
            }
            count=0;
    }
    printf("%d %d %d %d %d %d %d",jiang[0],jiang[1],jiang[2],jiang[3],jiang[4],jiang[5],jiang[6]);
}
