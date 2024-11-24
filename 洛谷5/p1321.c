#include<stdio.h>
#include<string.h>

int main(){
    char nm[260];
    scanf("%s",nm);
    int nmlgd=strlen(nm);
    int b=0;
    int g=0;
    for(int i = 0 ;i<nmlgd;i++){
        if(nm[i]!='.'){
            if(nm[i]=='b'){
                if(nm[i+1]=='o'){
                    if(nm[i+2]=='y'){
                        b++;
                        i+=2;
                    }else{
                        b++;
                        i++;
                    }
                }else{
                    b++;
                }
            }
            else if(nm[i]=='o'){
                if(nm[i+1]=='y'){
                    b++;
                    i++;
                }else{
                    b++;
                }
            }
            else if(nm[i]=='y'){
                b++;
            }
            else if(nm[i]=='g'){
                if(nm[i+1]=='i'){
                    if(nm[i+2]=='r'){
                        if(nm[i+3]=='l'){
                            g++;
                            i+=3;
                        }else{
                            g++;
                            i+=2;
                        }
                    }else{
                        g++;
                        i++;
                    }
                }else{
                    g++;
                }
            }
            else if(nm[i]=='i'){
                if(nm[i+1]=='r'){
                    if(nm[i+2]=='l'){
                        i+=2;
                        g++;
                    }else{
                        i++;
                        g++;
                    }
                }else{
                    g++;
                }
            }
            else if(nm[i]=='r'){
                if(nm[i+1]=='l'){
                    i++;
                    g++;
                }else{
                    g++;
                }
            }
            else if(nm[i]=='l'){
                g++;
            }
        }
    }
    printf("%d\n%d",b,g);
}