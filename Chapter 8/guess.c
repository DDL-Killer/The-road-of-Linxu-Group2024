#include<stdio.h>
int main(){
    int guess;
    int low=1;
    int high=100;
    char response;

    while (low<=high){
        guess=(low+high)/2;
        printf("%d\n",guess);
        response=getchar();
       
        if(response=='y'){
            printf("right,it is %d\n",guess);
            break;
        }

        else if(response=='n'){
            printf("B or S?");
        

        while (getchar()!='\n')
        {
            continue;
        }
        response=getchar();

        if(response=='B'){
            high=guess-1;
        }
        else if(response=='S'){
            low=guess+1;
        }
        else{
            printf("Wrong!\n");
        }
                while (getchar() != '\n') {
            continue;
        }
        }
        
        if(low>high){
            printf("really?");
        }
    }}