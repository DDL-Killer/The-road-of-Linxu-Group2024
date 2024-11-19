#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int count=1;
    int temp=1;
    for(int i = 1;i<n;i++){
        if(a[i]==a[i-1]+1){
            temp++;
        }else{
            if(count<temp){
                count=temp;
            }
            temp=1;
        }
    }
    if(count<temp){
        count=temp;
    }
    printf("%d",count);
    return 0;

}
