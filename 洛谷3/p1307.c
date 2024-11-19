#include<stdio.h>
#include<stdlib.h>
int main(){
    char ch;
    char *a=(char*)malloc(1000000000*sizeof(char));
    int count=0;
    int panduan=0;
    while ((ch=getchar())!='\n')
    {
        if(ch=='-'){
            panduan=1;
        }else{
            a[count++]=ch;
        }

    }
    count--;
    if(panduan){
        printf("-");
    }
    if(a[count]=='0'&&count==0){
        printf("0");
        return 0;
    }
    int pan=0;
    while (a[count]=='0')
    {
        count--;
        if(a[count]!='0'){
            break;
        }
    }
    for(;count>=0;count--){
        printf("%c",a[count]);
    }
    
    
}