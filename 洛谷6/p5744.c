#include<stdio.h>
typedef struct 
{
    char name[20];
    int age;
    int grade;
}px;
int main(){
    int n;
    scanf("%d",&n);
    px pxs[n];
    for(int i = 0;i<n;i++)
    {
        scanf("%s %d %d",pxs[i].name,&pxs[i].age,&pxs[i].grade);
        if(pxs[i].grade*1.2>=600){
            pxs[i].grade=600;
        }else{
            pxs[i].grade*=1.2;
        }
    }
    for(int i = 0;i<n;i++){
        printf("%s %d %d\n",pxs[i].name,pxs[i].age+1,pxs[i].grade);
    }
}
