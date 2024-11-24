#include<stdio.h>
int daotao(int a){
    return (a+1)*2;
}
int main(){
    int day;
    scanf("%d",&day);
    int ab=1;
    for(int i = 1;i<day;i++){
        ab=daotao(ab);
    }
    printf("%d",ab);
}