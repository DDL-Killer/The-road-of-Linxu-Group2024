#include<stdio.h>
#include<string.h>
int main(){
    int zimu[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
    int sum=0;
    char shu[201];
    fgets(shu,201,stdin);
    int num=strlen(shu);
    if(shu[num-1]=='\n'){
        shu[--num]='\0';
    }
    for(int i =0;i<num;i++){
        if(shu[i]==' '){
            sum++;
        }else if(shu[i]>='a'&&shu[i]<='z'){
            sum+=zimu[shu[i]-'a'];
        }
    }
    printf("%d",sum);
}