#include<stdio.h>
int main(){
    int l,quyu;
    scanf("%d %d",&l,&quyu);
    int ditie[quyu][2];
    for(int i = 0;i<quyu;i++){
        scanf("%d %d",&ditie[i][0],&ditie[i][1]);
    }
    int shu[l+1];
    for(int i = 0 ; i <= l;i++){
        shu[i]=1;
    }
    for(int i = 0;i<quyu;i++){
        for(int j = ditie[i][0];j<=ditie[i][1];j++)
        {
            shu[j]=0;
        }
    }
    int sum=0;
    for(int i = 0;i<=l;i++){
        sum+=shu[i];
    }
    printf("%d",sum);
}