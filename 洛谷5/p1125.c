#include<stdio.h>
#include<math.h>
#include<string.h>
int zhishu(int a){
    if(a<2) return 0;
    else if(a==2) return 1;
    else if(a%2==0) return 0;
    else{
        for(int i = 2;i<=sqrt(a);i++){
            if(a%i==0) return 0;
        }
        return 1;
    }
}
int main(){
    char ab[101];
    scanf("%s",ab);
    int n = strlen(ab);
    int zimu[26]={0};
    for(int i = 0;i<n;i++){
        zimu[ab[i]-'a']+=1;
    }
    int max=-1;
    int min=101;
    for(int i = 0;i<26;i++){
        if(zimu[i]>max) max=zimu[i];
        if(zimu[i]<min&&zimu[i]!=0) min=zimu[i];
    }
    if(zhishu(max-min)){
        printf("Lucky Word\n%d",max-min);
    }else{
        printf("No Answer\n0");
    }

}