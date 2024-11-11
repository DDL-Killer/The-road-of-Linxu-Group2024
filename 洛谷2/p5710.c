#include<stdio.h>
int one(int a){
    if(a==0||a%2==0){
        return 1;
    }else{
        return 0;
    }
}
int two(int b){
    if(b>4&&b<=12){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int A,U,B,Z,num;
    A=U=B=Z=0;
    scanf("%d",&num);
    if(one(num)&&two(num)){
        A=1;
        U=1;
    }
    if(one(num)||two(num)){
        U=1;
    }
    if((one(num)&&!two(num))&&(!one(num)&&two(num))){
        B=1;
    }
    if(!one(num)&&!two(num)){
        Z=1;
    }
    printf("%d %d %d %d",A,U,B,Z);
    return 0;
}