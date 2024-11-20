#include<stdio.h>
int main(){
    int s1,s2,s3;
    scanf("%d %d %d",&s1,&s2,&s3);
    int imnb[s1+s2+s3+1];
    for(int i =0;i<=s1+s2+s3;i++){
        imnb[i]=0;
    }
    int sum;
    for(int i = 1;i<=s1;i++){
        for(int j = 1;j<=s2;j++){
            for(int z = 1;z<=s3;z++){
                sum=i+j+z;
                imnb[sum]+=1;
            }
        }
    }
    int res;
    int max=0;
    for(int i =3;i<=s1+s2+s3;i++){
        if(imnb[i]>max){
            max=imnb[i];
            res=i;
        }
    }
    printf("%d",res);
}