#include<stdio.h>
#include<stdlib.h>
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int jiangxu(const void *a,const void *b){
    int aa,bb;
    aa=*(int *)a;
    bb=*(int *)b;
    if(aa<bb) return -1;
    else if(aa>bb) return 1;
    else return 0;
}
int main(){
    int a,b,c,gongyue;
    int san[3];
    scanf("%d %d %d",&san[0],&san[1],&san[2]);
    qsort(san,3,sizeof(int),jiangxu);
    gongyue=gcd(san[0],san[2]);
    printf("%d/%d",san[0]/gongyue,san[2]/gongyue);
}