#include<stdio.h>
#include<string.h>

int main(){
    int a=0,b=0,c=0;
    char aaa[1000];
    scanf("%s",aaa);
    int chang=strlen(aaa);
    for(int i = 0;i<chang;i+=5){
    switch(aaa[i]){
			case 'a': {
				switch(aaa[i+3]){
					case 'a': a=a;break;
					case 'b': a=b;break;
					case 'c': a=c;break;
					default: a=aaa[i+3]-'0';
				}
				break;
			}
			case 'b': {
				switch(aaa[i+3]){
					case 'a': b=a;break;
					case 'b': b=b;break;
					case 'c': b=c;break;
					default: b=aaa[i+3]-'0';
				}
				break;
			}
			case 'c': {
				switch(aaa[i+3]){
                	case 'a': c=a;break;
					case 'b': c=b;break;
					case 'c': c=c;break;
					default: c=aaa[i+3]-'0';
				}
				break;
			}						
		}
    }
    printf("%d %d %d",a,b,c);
}