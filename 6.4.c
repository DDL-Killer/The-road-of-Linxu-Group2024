#include<stdio.h>
int main(){
    int i,j;
    char letter='A';
    for(i=0;i<6;i++){
        for(j=0;j<i+1;j++){
            printf("%c",letter);
            letter++;
        }

        printf("\n");
    }
}
