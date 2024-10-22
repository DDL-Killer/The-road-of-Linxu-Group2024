#include<stdio.h>
int main(){
    char a;
    int count=0;
    while ((a=getchar())!='#')
    {
        switch (a)
        {
        case '!':
            putchar('!');
            putchar('!');
            count++;/* code */
            break;
        case'.':
            putchar('!');
            count++;
            break;
        
        default:
            putchar(a);
            break;
        }
    }
    printf("%d",count);
    
}