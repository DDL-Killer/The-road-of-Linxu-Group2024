#include<stdio.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int js[11];
    int count=0;
    int num[10]={0,0,0,0,0,0,0,0,0,0};
    for(int i = a;i<=b;i++){
        int x=i;
        while (x!=0)
        {
            js[count++]=x%10;
            x/=10;
        }
        for(int a = 0;a<count;a++){
            for(int j = 0;j<10;j++){
                if(js[a]==j){
                    num[j]+=1;
                }
            }
        }
        count=0;
    }
    printf("%d %d %d %d %d %d %d %d %d %d",num[0],num[1],num[2],num[3],num[4],num[5],num[6],num[7],num[8],num[9]);
}