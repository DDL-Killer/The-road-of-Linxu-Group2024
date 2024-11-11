#include<stdio.h>
#include<stdlib.h>
int bijiao(const void* a,const void *b){
    int aa=*(int *)a;
    int bb=*(int *)b;
    if(aa<bb) return -1;
    else if(aa>bb) return 1;
    else return 0;
}
void shuchu(int a,int b,int c){
    if(a+b>c&&a+c>b&&b+c>a){
        if(a*a+b*b==c*c){
            printf("Right triangle\n");
        }
        if(a*a+b*b>c*c){
            printf("Acute triangle\n");
        }
        if(a*a+b*b<c*c){
            printf("Obtuse triangle\n");
        }
        if((a==b&&a!=c)||(a==c&&a!=b)||(b==c&&b!=a)){
            printf("Isosceles triangle\n");
        }
        if(a==b&&a==c){
            printf("Isosceles triangle\n");
            printf("Equilateral triangle\n");
        }
    }else{
        printf("Not triangle");
    }
}
int main(){
    int san[3];
    scanf("%d %d %d",&san[0],&san[1],&san[2]);
    qsort(san,3,sizeof(int),bijiao);
    shuchu(san[0],san[1],san[2]);
}