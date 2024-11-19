#include<stdio.h>
#include<stdlib.h>
int shengxu(const void * a,const void * b){
    int aa=*(int*)a;
    int bb=*(int*)b;
    if(aa<bb) return -1;
    else if(aa>bb) return 1;
    else return 0;
}
int main(){
    int num;
    scanf("%d",&num);
    int a[num];
    for(int i = 0;i<num;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,num,sizeof(int),shengxu);
    int sum=0;
    for(int j = 1;j<num-1;j++){
        sum+=a[j];
    }
    float res=sum/(float)(num-2);
    printf("%.2f",res);
}