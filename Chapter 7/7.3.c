#include<stdio.h>
int main(){
    int j,o,sumj,sumo,a;
    j=o=sumj=sumo=0;
    double ou,ji;
    ou=ji=0.0;
    while (1)
    {
        scanf("%d",&a);
        if(a!=0){
            if(a%2==0){
                o++;
                sumo+=a;
            }
            else{
                j++;
                sumj+=a;
            }
        }
        else{
            break;
        }
    }
    if(o>0){
        ou=sumo/(double)o;}
    if(j>0){
        ji=sumj/(double)j;}
    printf("the number of oushu is %d ,average is %.2lf\n",o,ou);
    printf("the number of jishu is %d ,average is %.2lf",j,ji);
}