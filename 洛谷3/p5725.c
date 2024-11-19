#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int jv=1;
    int san=1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            printf("%02d",jv);
            jv++;
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 1;i<=n;i++){
                    for(int z = 0;z<n-i;z++){
                printf("  ");
            }
        for(int j=0;j<i;j++){
            printf("%02d",san);
            san++;
        }
        printf("\n");
    }
}