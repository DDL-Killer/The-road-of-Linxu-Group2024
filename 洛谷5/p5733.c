#include<stdio.h>
int main(){
    char ch;
    while ((ch=getchar())!='\n')
    {
        if(ch>='a'&&ch<='z'){
            putchar(ch-'a'+'A');
        }
        else{
            putchar(ch);
        }
    }
    
}