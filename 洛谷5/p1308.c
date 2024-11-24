#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    char iput[11];
    char wput[1000001];
    scanf("%s",iput);
    getchar();
    fgets(wput,1000001,stdin);
    int num1=strlen(iput);
    for(int i = 0;i<num1;i++){
       iput[i] = tolower(iput[i]);
    }
    int num2=strlen(wput);
    if (wput[num2 - 1] == '\n') { // 如果有换行符，移除它
        wput[--num2] = '\0';
    }   
    for(int i = 0;i<num2;i++){
        wput[i] = tolower(wput[i]);
    }
    int where=-1;
    int count=0;

    for(int i = 0;i<=num2-num1;i++){
        int pan=1;
        for(int j = 0;j<num1;j++){
            if(iput[j]!=wput[j+i]){
                pan=0;
                break;
            }
        }
        if(pan){
            if ((i == 0 || wput[i - 1] == ' ') && (i + num1 == num2 || wput[i + num1] == ' ')) {
            count++;
            if(where==-1){
            where=i;
            }
        }
    }
}
    if(count==0){
        printf("-1");
        return 0;
    }else{
        printf("%d %d",count,where);
    }
}