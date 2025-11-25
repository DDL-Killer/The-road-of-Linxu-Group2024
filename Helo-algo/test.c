#include<stdio.h>
#include<stdlib.h>

// void get_next(const char *p,int *next,int len){
//     //k表示最长公共前后缀的长度
//     //j表示当前遍历到的p[j]

//     next[0] = 0;
//     int k = 0;
//     for(int j = 1;j<len;j++){
//         while(k>0&&p[j] != p[k]){
//             k = next[k-1];
//         }

//         if(p[j] == p[k]){
//             k++;
//         }

//         next[j] = k;
//     }

// }

// void get_next(const char *p,int *next,int len){
//     int k = 0;
//     next[0] = 0;
//     for(int j = 1;j<len;j++){
//         while(k>0 && p[j] != p[k]){
//             k = next[k-1];
//         }
//         if(p[j] == p[k]){
//             k++;
//         }
//         next[j] = k;
//     }
// }

// int kmp_search_v2(const char *S, const char *P, const int *next){
//     int s_len = strlen(S);
//     int p_len = strlen(P);
//     int i = 0,j = 0;
//     while(i<s_len){
//         if(S[i] == P[j]){
//             i++;
//             j++;
//         }else if(j>0){
//             j = next[j-1];
//         }else{
//             i++;
//         }
//         if(j == p_len){
//             return i-j;
//         }
//     }
//     return -1;
// }





//{
//     int k = 0;
//     next[0] = 0;
//     for(int j = 1;j<len;j++){
//         while(k>0&&p[j] != p[k]){
//             k = next[k-1];
//         }
//         if(p[j] == p[k]){
//             k++;
//         }
//         next[j] = k;
//     }
// }

// void get_next(const char *p,int *next,int len){
//     int k = 0;
//     next[0] = 0;
//     for(int j = 1;j<len;j++){
//         while(k>0&&p[j]!=p[k]){
//             k = next[k-1];
//         }
//         if(p[j] == p[k]){
//             k++;
//         }
//         next[j] = k;
//     }
// }

// int kmp_search(const char *S,const char *P,const int *next){
//     int s_len = strlen(S);
//     int p_len = strlen(P);

//     int i = 0; //主串S的指针
//     int j = 0; //模式串P的指针

//     while(i < s_len){
//         //1. 匹配成功
//         if(j == 0 || S[i] == P[j]){
//             if(S[i] == P[j]){
//                 j++;
//             }
//             i++; //i 永远向后移动
//         //2. 发生失配
//         }else{
//             j = next[j-1];
//         }

//         if(j == p_len){
//             return i-j;
//         }
//     }
//     return -1;
// }

// int kmp_search2(const char *S,const char *P,const int *next){
//     int s_len = strlen(S);
//     int p_len = strlen(P);
//     int i = 0,j = 0;

//     while(i<s_len){
//         if(S[i] == P[j]){
//             j++;
//             i++;
//         }else if(j>0){
//             j = next[j-1];
//         }else{
//             i++;
//         }

//         if(j = p_len){
//             return i-j;
//         }
//     }
//     return -1;
// }

//求二叉树度为2的结点个数
int Degree2(Bitree bt){
    if(bt == NULL){
        return 0;
    }

    if(bt->Lchild!=NULL && bt->Rchild != NULL){
        return 1 + Degree2(bt->Lchild) + Degree2(bt->Rchild);
    }else{
        return Degree2(bt->Lchild) + Degree2(bt->Rchild);
    }
}

//交换二叉树的左右子树
void Swaplr(Bitree bt){
    if(bt == NULL){
        return ;
    }

    Swaplr(bt->Lchild);
    Swaplr(bt->Rchild);

    Bitree temp;
    temp = bt->Lchild;
    bt->Lchild = bt->Rchild;
    bt->Rchild = temp;
}

//先序输出各结点及其层次
void PreOrderLayer(Bitree bt,int lay){
    if(bt == NULL){
        return;
    }

    print("(%c,%d)",bt->data,lay);
    PreOrderLayer(bt->Lchild,lay+1);
    PreOrderLayer(bt->Rchild,lay+1);
}

//求树的叶子结点数
int NumOfleaf(Cstree rt){
    if(rt == NULL){
        return 0;
    }

    if(rt->FirstChild == NULL){
        return 1 + NumOfleaf(rt->NextSIbling);
    }else{
        return NumOfleaf(rt->FirstCHild) + NumOfleaf(rt->NextSIbling);
    }
}

//求树的高度
int GetHeight(Cstree rt){
    if(rt == NULL){
        return 0;
    }

    int hei1 = 1 + GetHeight(rt->Firstchild);
    int hei2 = Get(rt->Next);

    if(hei1>hei2){
        return hei1;
    }else{
        return hei2;
    }
}