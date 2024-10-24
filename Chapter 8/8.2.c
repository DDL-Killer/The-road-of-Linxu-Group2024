#include<stdio.h>
int main(){
    int b=0;
    char a;
    while ((a=getchar())!=EOF)
    {
        b++;
        if(b%10==0){
            putchar(a);/* code */
    }
        while(getchar()!='\n')
        {
            continue;
        }
    
}}