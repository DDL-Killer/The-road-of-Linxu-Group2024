#include<stdio.h>
#include<string.h>

int main(){
    int n;
    scanf("%d",&n);
    char ch[51];
    scanf("%s",ch);
    int nb = strlen(ch);
    for(int i=0;i<nb;i++){
        if((ch[i]+n)>'z'){
            printf("%c",ch[i]+n-26);
        }else{
            printf("%c",ch[i]+n);
        }
    }
}