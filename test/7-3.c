#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    char name[100];
    int huxi;
    int maibo;
    for(int i = 0;i<N;i++){
        scanf("%s %d %d",name,&huxi,&maibo);
                if(huxi>20||huxi<15||maibo>70||maibo<50){
            printf("%s\n",name);
        }
    }

}