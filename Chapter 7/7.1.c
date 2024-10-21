#include<stdio.h>
int main(){
    char ch;
    int space,huiche,other;
    space=huiche=other=0;
    while ((ch=getchar())!='#')
    {
        if(ch == ' '){
            space++;
        }
        else if (ch == '\n')
        {
            huiche++;
        }
        else{
            other++;
        }
        
    }
    printf("%d %d %d",space,huiche,other);
    
}