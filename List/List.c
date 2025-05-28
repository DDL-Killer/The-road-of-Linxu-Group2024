#include<stdio.h>
/*
void union1(List *La,List Lb){
    int La_len,Lb_len,i;
    ElemType e;
    La_len = ListLength (La);
    Lb_len = ListLength (Lb);
    for(int i = 1;i<=Lb_len;i++){
        GetElem(Lb,i,e);
        if(!LocateElem(La,e,equal)){
            ListInsert(La,++La_len,e);
        }
    }
}
*/

//创建数组

#define MAXSIZE 20   //存储空间初始分配量
typedef int ElemType;  // 类型跟实践而定

typedef struct {
    ElemType data[MAXSIZE];  //数组存储数据元素，最大为MAXSIZE
    int length;   //线性表当前长度
}SqList;


//获得元素：将线性表的第i个元素获得

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

//初始条件，顺序线性表L已存在
Status GetElem (SqList L,int i,ElemType *e){
    if(L.length==0||i<1||i>L.length){
        return ERROR;
    }
    *e = L.data[i-1];
    return OK;
}

//插入操作：在L中的第i个位置之前插入新的数据元素e,i的长度加1

Status ListInsert (SqList *L,int i,ElemType e){
    int k;
    if(L->length==MAXSIZE){     /*线性表满*/
        return ERROR;
    }
    if(i<1||i>L->length+1){     /*i不在范围内*/
        return ERROR;
    }
    if(i<=L->length){           /*插入数据不在表尾*/
        for(k=L->length-1;k>=i-1;k--){
            L->data[k+1]=L->data[k];
        }
    }
    L->data[i-1]=e;
    L->length++;
    return OK;
}




