#include<stdio.h>
#include<stdlib.h>
int main(){
    char ch;
    char *a=(char*)malloc(100000*sizeof(char));
    int count=0;
    int panduan=0;
    while ((ch=getchar())!='\n'&&ch!=EOF)
    {
        if(ch=='-'){
            panduan=1;
        }else if(ch >= '0' && ch <= '9'){
            a[count++]=ch;
        }
    }

    if (count == 1 && a[0] == '0') {
        printf("0");
        free(a);
        return 0;
    }
    count--;
    if(panduan){
        printf("-");
    }
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
    free(a);
    return 0;
}
