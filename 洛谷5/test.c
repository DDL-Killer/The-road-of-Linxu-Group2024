#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int nzi[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char end[600]="";
    char huan[200];
    for(int i =0;i<4;i++){
        fgets(huan,199,stdin);
        huan[strcspn(huan,"\n")]=' ';
        strcat(end,huan);
    }
    int num=strlen(end);
    for(int i = 0;i<num;i++){
        printf("%c",end[i]);
    }
}