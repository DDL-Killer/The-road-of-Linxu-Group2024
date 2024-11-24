#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int shengxu(const void*a,const void*b){
    int aa=*(int*)a;
    int bb=*(int*)b;
    if(aa<bb) return -1;
    else if(aa>bb) return 1;
    else return 0;
}
int main(){
    char a[26][20]={"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"," twenty","a","both","another","first","secend","third"};
    int b[26]={1,4,9,16,25,36,49,64,81,00,21,44,69,96,25,56,89,24,61,0,1,4,1,1,4,9};
    int cun[10],top=0,flag=0;

    int i,j;
    char s[100];
    for(i = 0;i<6;i++){
        scanf("%s",s);
        for(j=0;j<26;j++){
            if(!strcmp(s,a[j])){
                cun[top++]=b[j];
                break;
            }
        }
    }
    qsort(cun,top,sizeof(int),shengxu);

    for(int i =0;i<top;i++){
        if(flag){
            printf("%02d",cun[i]);
        }else{
            if(cun[i]){
                printf("%d",cun[i]);
                flag=1;
            }
        }
    }
    if(!flag) printf("0");
    return 0;

}