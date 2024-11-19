#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int count=1;
    int ii=n;
    for(int i = 0;i<=n;i++){

        for(int j=ii--;j>0;j--){
            printf("%02d",count++);
        }
        printf("\n");
    }
}