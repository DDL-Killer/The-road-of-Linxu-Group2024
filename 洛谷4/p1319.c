#include<stdio.h>
#include<string.h>
int main(){
    int n,a;
    scanf("%d",&n);
    int  shu=n*n;
    int num=0;
    int count=0;
    while (shu)
    {
        scanf("%d",&a);
        shu-=a;
        for(int i = 0;i<a;i++){
            printf("%d",num);
            count++;
        if(count==n){
            count=0;
            printf("\n");
            }
        }
    num=!num;
    }
}
