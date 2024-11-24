#include<stdio.h>
#include<string.h>
int main(){
    int shuzi[26]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
    char a1[7];
    char a2[7];
    scanf("%s",a1);
    scanf("%s",a2);
    int n1=1,n2=1;
    int len1,len2;
    len1=strlen(a1);
    len2=strlen(a2);
    for(int i =0;i<len1;i++){
        n1*=shuzi[a1[i]-'A'];
    }
    for(int i =0;i<len2;i++){
        n2*=shuzi[a2[i]-'A'];
    }
    if((n1%47)==(n2%47)){
        printf("GO");
        return 0;
    }else{
        printf("STAY");
        return 0;
    }

}