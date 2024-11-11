#include<stdio.h>
int main(){
char a[14];
int count=1;
int sum=0;
scanf("%s",a);
for(int i=0;i<11;i++){
    if(i!=1&&i!=5){
        sum+=(a[i]-'0')*count;
        count++;
    }
}
int num = sum % 11;

    // 检查识别码
    if ((num == 10 && a[12] == 'X') || (num != 10 && a[12] == (num + '0'))) {
        printf("Right\n");
    } else {
        // 输出正确的ISBN号码
        if (num == 10) {
            printf("%c%c%c%c%c%c%c%c%c%c%c%cX\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], a[10], a[11]);
        } else {
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], a[10], a[11], num);
        }
    }

    return 0;
}
