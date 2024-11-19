#include<stdio.h>
#include<stdlib.h>
int shengxu(const void* a,const void * b){
    int aa=*(int *)a;
    int bb=*(int *)b;
    if(aa<bb) return -1;
    else if(aa>bb) return 1;
    else return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),shengxu);
    printf("%d",a[n-1]-a[0]);
}