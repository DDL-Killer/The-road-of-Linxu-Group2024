#include<stdio.h>
#define a 60

int main(){
    int h,m,input;
    scanf("%d",&input);


    while(input>0){
        h=input/a;
        m=input%a;
    printf("%02d:%02d",h,m);
    scanf("%d",&input);
    }
    

    return 0;
}