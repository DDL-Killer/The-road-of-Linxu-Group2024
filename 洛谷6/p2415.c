#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main(){
    char input[1000];
    int *num=NULL;
    int count=0;
    fgets(input,sizeof(input),stdin);
    input[strcspn(input, "\n")]='\0';
    char *token=strtok(input," ");
    while (token!=NULL){
        int *temp=realloc(num,(count+1)*sizeof(int));
        num=temp;
        num[count++]=atoi(token);
        token=strtok(NULL," ");
    }
    long long sum=0;
    for(int i = 0;i<count;i++){
        sum+=(long long)num[i];
    }
    long long cishu=(long long)pow(2,count-1);
    long long res=cishu*sum;
    printf("%lld",res);
}