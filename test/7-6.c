#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    char A;
    char leixing[num+1];
    for(int i = 0;i<num;i++){
        leixing[i]='A'+i;
    }
    for(int i = 0;i<2*num-1;i++){
        for(int j = 0;j<2*num-1;j++){
            int panduan;
            if(i<num){
                panduan=i;
            }else{
                panduan=2*num-1-(i+1);
            }
            int lie=j;
            if(j>=num){
                lie=num*2-1-(j+1);
            }
            if(panduan>lie){
                panduan=lie;
            }
            printf("%c",leixing[panduan]);
        }
        printf("\n");
    }

}