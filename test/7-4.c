#include<stdio.h>
#define gangti 1.26
#define liuti 2.455
int main(){
    float kaifang,shuxing,jvli;
    double res;
    scanf("%f %f %f",&kaifang,&shuxing,&jvli);
    if(shuxing){
        res=kaifang*gangti;
    }else{
        res=kaifang*liuti;
    }
    if(res<jvli){
        printf("%.2lf ^_^",res);
    }else{
        printf("%.2lf T_T",res);
    }
}