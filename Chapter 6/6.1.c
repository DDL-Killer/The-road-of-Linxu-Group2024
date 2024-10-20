#include<stdio.h>
int main(){
    char a[26];
    for(int i=0;i<26;i++){
        a[i]='a'+i;
    }
    for(int j=0;j<26;j++){
        printf("%c ",a[j]);
    } 
}