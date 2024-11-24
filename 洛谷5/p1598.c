#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
    int nzi[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char end[600]="";
    char huan[200];
    for(int i =0;i<4;i++){
        fgets(huan,199,stdin);
        huan[strcspn(huan,"\n")]='\0';
        strcat(end,huan);
    }
    int num=strlen(end);
    for(int i =0;i<num;i++){
        if(isalpha(end[i])&&isupper(end[i])){
            nzi[end[i]-'A']+=1;
        }
    }
    int max=0;
    for(int i =0;i<26;i++){
        if(nzi[i]>max){
            max=nzi[i];
        }
    }
    char res[max+1][26];
    memset(res,' ',sizeof(res));
    for(int i = 0;i<max;i++){
        for(int j = 0;j<26;j++){
        res[i][j]=(nzi[j]>=max-i)?'*':' ';
        }
    }
    for(int j = 0;j<26;j++){
        res[max][j]='A'+j;
    }
    for(int i = 0;i<=max;i++){
        for(int j = 0;j<26;j++){
            printf("%c",res[i][j]);
            if(j<25){
                printf(" ");
            }
        }
        if(i<max){
            printf("\n");
        }
    }
}