#include<stdio.h>
#include<string.h>
int wei(int a){
    int count=0;
    if(a==0){
        return 1;
    }
    if(a>0){
        while(a){
            a/=10;
            ++count;
        }
    }
    if(a<0){
        count=1;
        a=-a;
        while(a){
            a/=10;
            ++count;
        }
    }
    return count;
}
int main(){
    int a;
    scanf("%d",&a);
    int n1,n2;
    int len;
    char huan;
    char c[10];
    for(int i = 0 ;i<a;i++){
        scanf("%s",c);
        int count;
        switch (c[0])
        {
        case 'a':
            scanf("%d %d",&n1,&n2);
            printf("%d+%d=%d\n",n1,n2,n1+n2);
            count = wei(n1+n2)+wei(n2)+wei(n1)+2;
            huan=c[0];
            break;
        case 'b':
            scanf("%d %d",&n1,&n2);
            printf("%d-%d=%d\n",n1,n2,n1-n2);
            count = wei(n1-n2)+wei(n2)+wei(n1)+2;
            huan=c[0];
            break;
        case 'c':
            scanf("%d %d",&n1,&n2);
            printf("%d*%d=%d\n",n1,n2,n1*n2);
            count = wei(n1*n2)+wei(n2)+wei(n1)+2;
            huan=c[0];
            break;
        default:
            scanf("%d",&n2);
            n1=0;
            int len=strlen(c);
            for(int i = 0;i<len;i++){
                n1=n1*10+c[i]-'0';
            }
            switch (huan)
            {
                case 'a':
                    printf("%d+%d=%d\n",n1,n2,n1+n2);
                    count = wei(n1+n2)+wei(n2)+wei(n1)+2;
                break;
                case 'b':
                    printf("%d-%d=%d\n",n1,n2,n1-n2);
                    count = wei(n1-n2)+wei(n2)+wei(n1)+2;
                break;
                case 'c':
                    printf("%d*%d=%d\n",n1,n2,n1*n2);
                    count = wei(n1*n2)+wei(n2)+wei(n1)+2;
                break;
            default:
                break;
            }
            break;
        }
        printf("%d\n",count);
    }
}