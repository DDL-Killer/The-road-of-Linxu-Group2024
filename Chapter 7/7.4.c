#include<stdio.h>
int main(){
    char input;
    int count=0;
    while ((input=getchar())!='#')
    {
        if(input=='.'){
            putchar('!');
            count++;
        }
        else if(input=='!'){
            putchar('!');
            putchar('!');
            count++;
        }
        else{
            putchar(input);
        }
    }
    printf("%d",count);
}