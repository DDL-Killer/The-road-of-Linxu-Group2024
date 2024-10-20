#include<stdio.h>
float jisuan(float a,float b){

        float res=(a-b)/(a*b);
        return res;
        
}
int main(){
    float a,b;
    int c;
    c =scanf("%f %f",&a,&b);
while(c == 2 ){
    float res = jisuan(a,b);
    printf("%.2f",res);
    c =scanf("%f %f",&a,&b);
}

}