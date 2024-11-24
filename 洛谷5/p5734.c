#include<stdio.h>
#include<string.h>
int main(){
    int cishu;
    scanf("%d",&cishu);
    char ab[1000];
    scanf("%s",ab);
    for(int i = 0;i<cishu;i++){
        int caozuo;
        scanf("%d",&caozuo);
        switch (caozuo)
        {
        case 1:
            char ab1[1000];
            scanf("%s",ab1);
            strcat(ab,ab1);
            printf("%s\n",ab);
            break;
        case 2:
            int a,b;
            int z=0;
            scanf("%d %d",&a,&b);
            char temp[1000]={0};
            strncpy(temp,ab+a,b);
            temp[b]='\0';
            strcpy(ab,temp);
            printf("%s\n",ab);
            break;
        case 3:
            int x;
            scanf("%d",&x);
            char ab2[1000];
            scanf("%s",ab2);
            char temp1[1000]={0};
            strncpy(temp1,ab,x);
            temp1[x]='\0';
            strcat(temp1,ab2);
            strcat(temp1,ab+x);
            strcpy(ab,temp1);
            printf("%s\n",ab);
            break;
        case 4:
            char ch[1000];
            scanf("%s",ch);
            int num4=strlen(ch);
            int num=strlen(ab);
            int where=-1;
            for(int i = 0;i<=num-num4;i++){
                int pan=1;
                for(int j = 0 ;j<num4;j++){
                    if(ch[j]!=ab[j+i]){
                        pan=0;
                        break;
                    }
                }
                if(pan){
                    if(where==-1){
                        where=i;
                    }
                }
            }
            printf("%d\n",where);
            break;   
        default:
            break;
        }
    }
}

