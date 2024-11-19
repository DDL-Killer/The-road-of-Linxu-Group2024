#include<stdio.h>
int main(){
    char ch;
    int count=0;
    int panduan=0;
    int first=1;
    while ((ch=getchar())!='.')
    {
        if(ch!=' '&&ch!='\n'){
            count++; 
            panduan=1;           
        }else if(ch==' '&&panduan){
            if(!first){
                printf(" ");
            }
            printf("%d",count);
            count=0;
            panduan=0;
            first=0;
        }
    }if(panduan||count>0){
        if(!first){
            printf(" ");
        }
    printf("%d",count);}
    
}
