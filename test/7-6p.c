#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int leixing[n];
    int jvli,liejvli;
    for(int i = 0;i<n;i++){
        leixing[i]='A'+i;
    }
    for(int i = 0;i<n*2-1;i++){
        jvli=i;
        for(int j = 0;j<n*2-1;j++){
        liejvli=j;
            if(i>=n){
                jvli=2*n-1-(i+1);
            }
            if(j>=n){
                liejvli=2*n-1-(j+1);
            }
            if(jvli>liejvli){
                jvli=liejvli;
            }
            printf("%c",leixing[jvli]);
        }
    printf("\n");
    }
}