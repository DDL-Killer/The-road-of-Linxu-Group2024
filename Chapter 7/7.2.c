#include<stdio.h>
int main(){
    char a;
    int count = 0;
    while ((a=getchar())!='#')
    {
        if(a!='\n'){
        printf("%c %4d  ",a,a);
        count++;
        }
        if(count%8==0){
            printf("\n");
        }
    }
    if(count %8!=0){
        printf("\n");
    }
    
}