#include<stdio.h>
int main(){
    char a;
    int count=0;
    while ((a=getchar())!= '#')
    {
        if(a=='e'){
            count++;
        }
        else if(a=='i'){
            count++;
        }
            /* code */
    }
    printf("%d",count);
}