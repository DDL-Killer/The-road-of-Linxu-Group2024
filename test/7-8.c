#include<stdio.h>
int main(){
    int m,n;
    scanf("%d\n%d",&m,&n);
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            printf("(%d,%d) ",i+1,j+1);
        }
        printf("\n");
    }
}