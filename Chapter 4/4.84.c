#include<stdio.h>
int main(){
    char name[20];
    float tall;
    scanf("%f %s",&tall,name);
    printf("%s ,you are %f feet tall",name,tall/10.0);
    return 0;
}