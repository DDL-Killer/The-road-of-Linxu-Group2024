#include<stdio.h>
int main(){
    int i,j,z,q;
    char a ;
    scanf("%c",&a);
    for(i=0;i<5;i++){
        for(z=0;z<4-i;z++){
            printf(" ");
        }
        for(j=0;j<i+1;j++){
            printf("%c",a+j);
        }
        for(q=i-1;q>=0;q--){
            printf("%c",a+q);
        }
        printf("\n");
    }
}