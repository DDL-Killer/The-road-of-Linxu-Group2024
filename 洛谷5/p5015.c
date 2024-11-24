#include<stdio.h>
#include<string.h>

int main(){
    char ch[20];
    fgets(ch,20,stdin);
    int num=strlen(ch);
    int sum=0;
    for(int i = 0;i <num;i++){
        if(ch[i]!=' '&&ch[i]!='\n'){
            sum++;
        }
    }
    printf("%d",sum);
}