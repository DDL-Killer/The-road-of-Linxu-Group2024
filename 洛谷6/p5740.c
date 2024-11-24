#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    char max[10];
    char huan[10];
    int a=0,b=0,c=0,sum=-1;
    int ta,tb,tc,tsum;
    for(int i = 0;i<n;i++){
        scanf("%s",huan);
        scanf("%d %d %d",&ta,&tb,&tc);
        tsum=ta+tb+tc;
        if(tsum>sum){
            a=ta;
            b=tb;
            c=tc;
            sum=tsum;
            int len=strlen(huan);
            strncpy(max,huan,len);
            max[len]='\0';
        }
    }
    printf("%s %d %d %d",max,a,b,c);  
}

