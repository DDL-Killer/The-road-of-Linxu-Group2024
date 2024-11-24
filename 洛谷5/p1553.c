#include<stdio.h>
#include<string.h>

int main(){
    char num[400];
    char huan1[400];
    char huan2[400];
    scanf("%s",num);
    int b = strlen(num);
    int pan=0;
    int wei;
    char fuhao;
    int nn1=0,nn2=0;
    int pp=0;
    int quanlin=1;
    for(int i = 0;i<b;i++){
        if (num[i] != '0' && num[i] != '.' && num[i] != '/' && num[i] != '%') {
            quanlin = 0;
            break;
        }
    }
    if(quanlin){
        if (strchr(num, '.')){
            printf("0.0\n");
        }
         else if (strchr(num, '%')) {
            printf("0%%\n"); 
        } else {
            printf("0\n");
        }
        return 0;
    } 
    for(int i = 0;i<b;i++){
        if(num[i]=='.'||num[i]=='/'||num[i]=='%'){
            pan=1;
            break;
        }
    }
    if(!pan){
        int tou=1;
        for(int i = b-1;i>=0;i--){
            if(tou && num[i]!='0'){
                printf("%c",num[i]);
                tou=0;
            }
            else if(!tou){
                printf("%c",num[i]);
            }
        }
    }else{
        for(int i = 0;i<b;i++){
            if(num[i]!='.'&&num[i]!='/'&&num[i]!='%'&&pp==0){
                huan1[nn1++]=num[i];
            }else if(num[i]=='.'||num[i]=='/'||num[i]=='%'){
                fuhao = num[i];
                pp=1;
            }else if(pp==1){
                huan2[nn2++]=num[i];
            }
        }
    
    int tou = 1;
    if(huan1[0]=='0'){
        printf("0");
    }else{
    for(int i = nn1-1;i>=0;i--){
        if(huan1[i]!='0'&&tou){
            printf("%c",huan1[i]);
            tou = 0;
        }else if(!tou){
            printf("%c",huan1[i]);
        }
    }}
    printf("%c",fuhao);
    int count = 0;
    for(int i = 0;i<nn2;i++){
        if(huan2[0]=='0'&&huan2[i]=='0'){
            count++;
        }else{
            break;
        }
    }
    tou = 1;
    if(count==nn2&&fuhao=='.'){
        printf("0");
        return 0;
    }
    for(int i = nn2-1;i>=count;i--){
        if(huan2[i]!='0'&&tou){
            printf("%c",huan2[i]);
            tou = 0;
        }else if(!tou){
            printf("%c",huan2[i]);
        }
    }
    }
}