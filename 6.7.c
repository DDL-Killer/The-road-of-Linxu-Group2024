#include<stdio.h>
#include<string.h>
int main(){
    char a[50];
    scanf("%s",a);
    int num=strlen(a);
    for(;num>=0;num--){
        printf("%c",a[num]);
    }
}