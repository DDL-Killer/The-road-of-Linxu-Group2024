#include<stdio.h>
#include<math.h>
void sushu(int n){

    for(int j=3;j<=n;j+=2){
            int lim=sqrt(j);
            int panduan=1;
        for(int x=2;x<=lim;x++){
            if(j%x==0){
                panduan=0;
                break;
            }
        }
        if(panduan){
            printf("%d ",j);
        }     
    }
    printf("\n");
}
int main(){
    int i;
    while (1)
    {
        scanf("%d",&i);
        if(i==2){
            printf("2\n");
        }
        else if(i>2&&i%2!=0){
            sushu(i);
        }
        else if(i==1||i%2==0&&i!=0){
            printf("NULL\n");
        }
        else if(i==0){
            return 0;
        }
        else{
            printf("Please input N+\n");
            continue;
        }
            /* code */
    }
    
}