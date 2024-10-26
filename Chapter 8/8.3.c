#include<stdio.h>
#include<ctype.h>
int main(){
    int daxie,xiaoxie;
    daxie=xiaoxie=0;
    char a;
    while ((a=getchar())!=EOF)
    {
        if(isupper(a)){
            daxie++;
        }
        else if(islower(a)){
            xiaoxie++;
        }
    }
    printf("daxie num is %d\n",daxie);
    printf("xiaoxie num is %d",xiaoxie);
    return 0;
    
}