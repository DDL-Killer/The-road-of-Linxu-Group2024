#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    char nb[10][5][3]=
    {
	{//0
		'X','X','X',
		'X','.','X',
		'X','.','X',
		'X','.','X',
		'X','X','X',
	},
	{//1
		'.','.','X',
		'.','.','X',
		'.','.','X',
		'.','.','X',
		'.','.','X',
	},
	{//2
		'X','X','X',
		'.','.','X',
		'X','X','X',
		'X','.','.',
		'X','X','X',
	},
	{//3
		'X','X','X',
		'.','.','X',
		'X','X','X',
		'.','.','X',
		'X','X','X',
	},
	{//4
		'X','.','X',
		'X','.','X',
		'X','X','X',
		'.','.','X',
		'.','.','X',
	},
	{//5
		'X','X','X',
		'X','.','.',
		'X','X','X',
		'.','.','X',
		'X','X','X',
	},
	{//6
		'X','X','X',
		'X','.','.',
		'X','X','X',
		'X','.','X',
		'X','X','X',
	},
	{//7
		'X','X','X',
		'.','.','X',
		'.','.','X',
		'.','.','X',
		'.','.','X',
	},
	{//8
		'X','X','X',
		'X','.','X',
		'X','X','X',
		'X','.','X',
		'X','X','X',
	},
	{//9
		'X','X','X',
		'X','.','X',
		'X','X','X',
		'.','.','X',
		'X','X','X',
	}
};
char nn[101];
for(int i = 0;i<num;i++){
scanf("%s",&nn[i]);}
for(int i = 0;i<5;i++){
    for(int j = 0;j<num;j++){
        for(int k =0;k<3;k++){
            printf("%c",nb[nn[j]-'0'][i][k]);
        }
        if(j!=num-1) printf(".");
    }
    printf("\n");
}
}