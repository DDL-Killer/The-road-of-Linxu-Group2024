#include<stdio.h>
#include<string.h>
int main(){
    int i,n,num,sum;
    char end[40000],suan[200];
    scanf("%s",&suan);
    n=strlen(suan);
    strcat(end,suan);
    for(i=1;i<n;i++){
    scanf("%s",suan);
    strcat(end,suan);
    }
    printf("%d ",n);
    for(i = 0,sum=0,num='0' ;i<=strlen(end);i++){
        if(end[i]==num){
            sum++;
        }else{
            num=end[i];
            printf("%d ",sum);
            sum=1;
        }
    }
    return 0;
    
}