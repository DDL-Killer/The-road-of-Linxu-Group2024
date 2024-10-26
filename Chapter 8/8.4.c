#include<stdio.h>
#include<ctype.h>
int main(){
    int count;
    char a;
    count=0;
    while ((a=getchar())!=EOF)
    {
        if(isalpha(a)){
           count++; 
        }

    }
    printf("num is %d",count);
    
}