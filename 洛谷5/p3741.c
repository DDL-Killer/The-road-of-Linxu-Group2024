#include<stdio.h>
#include<stdbool.h>
int main(){
    int num;
    scanf("%d",&num);
    char nm[101];
    int count=0;
    int pan=0;
    scanf("%s",nm);
    for(int i = 0;i<num-1;i++){
        if(nm[i]=='V'&&nm[i+1]=='K'){
            count++;
            nm[i]='i';
            nm[i+1]='i+1';
        }
    }
    for(int i = 0;i<num-1;i++){
        if(nm[i]==nm[i+1]){
            count++;
            break;
        }
    }
    printf("%d",count);
}