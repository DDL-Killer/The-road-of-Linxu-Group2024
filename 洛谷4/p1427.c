#include<stdio.h>
int main(){
    int a[100];
    int temp;
    int count=0;
    for(int i=0;i<100;i++){
        scanf("%d",&temp);
        if(temp==0){
            break;
        }
        a[i]=temp;
        count++;
    }
    count--;
    for(;count>=0;count--){
        printf("%d",a[count]);
        if(count!=0){
            printf(" ");
        }
    }
}
