#include<stdio.h>
int main(){
    int num,res;
    printf("This program computes mooduli.\nEnter an integer to serve as the second operand:");
    scanf("%d",&res);
    printf("Now enter the first operand:");
    scanf("%d",&num);
    printf("%d %% %d is %d\n",num,res,num%res);
    while(num>0){
        printf("Enter next number for first operand(<=0 to quit):");
        scanf("%d",&num);
        if(num<=0){
            printf("Done");
            break;
        }
        printf("%d %% %d is %d\n",num,res,num%res);
    }
}