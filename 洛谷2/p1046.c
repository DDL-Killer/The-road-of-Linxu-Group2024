#include<stdio.h>
#include<stdlib.h>
int jiangxu(const void* a,const void* b){
    int aa=*(int*)a;
    int bb=*(int*)b;
    if(aa<bb) return -1;
    else if(aa>bb) return 1;
    else return 0;
}
int main(){
    int apple[10];
    int high,count;
    count = 0;
    scanf("%d %d %d %d %d %d %d %d %d %d",&apple[0],&apple[1],&apple[2],&apple[3],&apple[4],&apple[5],&apple[6],&apple[7],&apple[8],&apple[9]);
    qsort(apple,10,sizeof(int),jiangxu);
    scanf("%d",&high);
    high+=30;
    for(int i = 0;i<10;i++){
        if(apple[i]<=high){
            count++;
        }else{
            break;
        }
    }
    printf("%d",count);
}