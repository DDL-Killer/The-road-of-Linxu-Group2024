#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    char name1[10];
    char name2[10];
}Pair;

int bijiao(const void * a,const void *b){
    Pair *pa=(Pair *)a;
    Pair *pb=(Pair *)b;
    int cmp1=strcmp(pa->name1,pb->name1);
    if(cmp1!=0) return cmp1;
    return strcmp(pa->name2,pb->name2);
}

int main(){
    int n,a,b,c;
    scanf("%d",&n);
    char mingzi[n][10];
    int shu[n][3];
    Pair *pairs=malloc(n*(n-1)/2*sizeof(Pair));
    int count=0;
    for(int i = 0;i<n;i++){
        scanf("%s",mingzi[i]);
        scanf("%d %d %d",&shu[i][0],&shu[i][1],&shu[i][2]);
    }
    for(int i = 0;i<n;i++){
        int sum=shu[i][0]+shu[i][1]+shu[i][2];
        for(int j = i+1;j<n;j++){
            int sum1=shu[j][0]+shu[j][1]+shu[j][2];
            if(abs(sum1-sum)<=10&&abs(shu[j][0]-shu[i][0])<=5&&abs(shu[j][1]-shu[i][1])<=5&&abs(shu[j][2]-shu[i][2])<=5){
                if(strcmp(mingzi[i],mingzi[j])<0){
                    strcpy(pairs[count].name1,mingzi[i]);
                    strcpy(pairs[count].name2,mingzi[j]);
                }else{
                    strcpy(pairs[count].name1,mingzi[j]);
                    strcpy(pairs[count].name2,mingzi[i]);   
                }
                count++;
            }
        }
    }
    qsort(pairs,count,sizeof(Pair),bijiao);
    for(int i = 0;i<count;i++){
        printf("%s %s\n",pairs[i].name1,pairs[i].name2);
    }   
}