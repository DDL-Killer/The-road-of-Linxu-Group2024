#include<stdio.h>
#include<stdlib.h>
int shengxu(const void*a,const void*b){
    int aa=*(int *)a;
    int bb=*(int *)b;
    if(aa<bb) return -1;
    else if(aa>bb) return 1;
    else return 0;
}
int main(){
    int a,i;
    scanf("%d",&a);
    int b[a];
    i=0;
 
    while(i<a){
        scanf("%d",&b[i]);
            i++;
        }

    qsort(b,a,sizeof(int),shengxu);
    printf("%d",b[0]);
    
}