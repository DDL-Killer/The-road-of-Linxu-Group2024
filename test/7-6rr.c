#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    int leixing[num];
    for(int i = 0 ; i<num;i++){
        leixing[i]='A'+i;
    }
    for(int i = 0;i<num*2-1;i++){
        for(int j = 0;j<num*2-1;j++){
            int jvli=i;
            int liejvli=j;
            if(i>=num) jvli=2*num-1-(i+1);
            if(j>=num) liejvli=2*num-1-(j+1);
            if(jvli>liejvli) jvli=liejvli;
            printf("%c",leixing[jvli]);
        }
        printf("\n");
    }

}