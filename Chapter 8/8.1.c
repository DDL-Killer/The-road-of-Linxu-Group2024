#include<stdio.h>
int main(){
    FILE *a;
    char name[100];
    int charcount=0;
    int ch;
    scanf("%s",name);
    a=fopen(name,"r");
    if(a==NULL){
        return 1;
    }
    while ((ch=fgetc(a))!=EOF)
    {
        charcount++;
    }
    fclose(a);
    printf("%d",charcount);
    return 0;
}