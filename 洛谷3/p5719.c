#include<stdio.h>
int main(){
    int ok[10000];
    int nok[10000];
    int n,k;
    int cok,cnok;
    cok=cnok=0;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        if(i%k==0){
            ok[cok]=i;
            cok++;
            continue;
        }else{
            nok[cnok]=i;
            cnok++;
            continue;
        }
    }
    float p1,p2;
    int sum1,sum2;
    sum1=sum2=0;
    for(int i=0;i<cok;i++){
        sum1+=ok[i];
    }
    for(int j=0;j<cnok;j++){
        sum2+=nok[j];
    }
    p1=(float)sum1/(cok*1.0);
    p2=(float)sum2/(cnok*1.0);
    printf("%.1f %.1f",p1,p2);
}