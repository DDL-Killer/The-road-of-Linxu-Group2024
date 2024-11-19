#include<stdio.h>
#include<math.h>
#include <stdlib.h>
int sushu(int a){
    if(a<2) return 0;
    else if(a==2) return 1;
    else if(a%2==0) return 0;
    else{
        for(int i = 3;i<=sqrt(a);i+=2){
            if(a%i==0){
                return 0;
            }
        }
        return 1;
    }
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    long int count=0;
    int *huiwen = (int *)malloc(1000000 * sizeof(int));  // 动态分配内存
    if (huiwen == NULL) {  // 检查内存分配是否成功
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    long int num=0;
    int d1,d2,d3,d4,d5,d6,d7,d8,d9;
    for(int d1 = 1;d1<=9;d1+=2){
        int temp = d1;
        if(sushu(temp)){
            huiwen[num++]=temp;
        }
    }
    for(int d1 = 1;d1<=9;d1+=2){
        int temp = d1*10+d1;
        if(sushu(temp)){
            huiwen[num++]=temp;
        } 
    }
    for(int d1=1;d1<=9;d1+=2){
        for(int d2 = 0;d2<=9;d2++){
            int temp=d1*100+d2*10+d1;
        if(sushu(temp)){
            huiwen[num++]=temp;
        } 
        }
    }
    for(int d1=1;d1<=9;d1+=2){
        for(int d2 = 0;d2<=9;d2++){
            for(int d3 =0;d3<=9;d3++){
            int temp=d1*10000+d2*1000+d3*100+d2*10+d1;
        if(sushu(temp)){
            huiwen[num++]=temp;
        } 
        }
    }}
    for(int d1=1;d1<=9;d1+=2){
        for(int d2 = 0;d2<=9;d2++){
            for(int d3 =0;d3<=9;d3++){
                for(int d4 = 0;d4<=9;d4++){
            int temp=d1*1000000+d2*100000+d3*10000+d4*1000+d3*100+d2*10+d1;
        if(sushu(temp)){
            huiwen[num++]=temp;
        } 
        }}
    }}
for (int d1 = 1; d1 <= 9; d1 += 2) {
    for (int d2 = 0; d2 <= 9; d2 ++) {
        for (int d3 = 0; d3 <= 9; d3 ++) {
            for (int d4 = 0; d4 <= 9; d4 ++) {
                int temp = d1 * 10000000 + d2 * 1000000 + d3 * 100000 + d4 * 10000 +
                           d4 * 1000 + d3 * 100 + d2 * 10 + d1;
                if (sushu(temp)) {
                    huiwen[num++] = temp;
                }
            }
        }
    }
}
    for(;count<num;count++){
        if (huiwen[count] >= a && huiwen[count] <= b) {
            printf("%d\n", huiwen[count]);
}}
    free(huiwen);
}