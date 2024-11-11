#include<stdio.h>
#include<stdlib.h>
int shengxu(const void*a,const void*b){
    int aa=*(int*)a;
    int bb=*(int*)b;
    if(aa<bb) return -1;
    else if(aa>bb) return 1;
    else return 0;
}
int main(){
    int num[3];
    char ab[4];
    scanf("%d %d %d\n%c%c%c",&num[0],&num[1],&num[2],&ab[0],&ab[1],&ab[2]);
    ab[3]='\0';
    qsort(num,3,sizeof(int),shengxu);
    for(int i=0;i<3;i++){
        if(ab[i]=='A'){
            printf("%d ",num[0]);
        }
        else if(ab[i]=='B'){
            printf("%d ",num[1]);
        }
        else{
            printf("%d ",num[2]);
        }
    }
    printf("\n");
}