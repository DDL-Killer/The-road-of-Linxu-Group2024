#include<stdio.h>
//链表节点结构体
typedef struct ListNode{
    int val;                 //节点值
    struct ListNode *next;   //指向下一节点的指针
}ListNode;

//构造函数
ListNode *newListNode(int val){
    ListNode *node;
    node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

//初始化链表
// ListNode* n0 = newListNode(1);
// ListNode* n1 = newListNode(3);
// ListNode* n2 = newListNode(2);
// ListNode* n3 = newListNode(5);
// ListNode* n4 = newListNode(4);
// n0->next = n1;
// n1->next = n2;
// n2->next = n3;
// n3->next = n4;

//在链表的节点n0之后插入节点P
void insert(ListNode *n0,ListNode *P){
    ListNode *n1 = n0->next;
    P->next = n1;
    n0->next = P;
}

//删除节点：只需改变一个节点的引用指针即可，删除链表的节点n0之后的首个节点
void removeItem(ListNode *n0){
    if(!n0->next)
        return;
    ListNode *P = n0->next;
    ListNode *n1 = P->next;
    n0->next = n1;
    free(P);
}

//访问节点：访问链表中索引为index的节点
ListNode *access(ListNode *head,int index){
    for(int i = 0;i<index;i++){
        if(head == NULL)
            return NULL;
        head = head->next;
    }
    return head;
}

//查找节点：在链表中查找值为target的节点，输出该节点在链表中的索引
int find(ListNode *head,int target){
    int index = 0;
    while (head)
    {
        if(head->val==target)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}

//双向链表结点结构体
typedef struct ListNode2{
    int val;                //节点值
    struct ListNode2 *next; //指向后继节点的指针 
    struct ListNode2 *prev; //指向前驱节点的指针
}ListNode2;

//构造函数
ListNode2 *newListNode2(int val){
    ListNode2 *node;
    node = (ListNode2 *)malloc(sizeof(ListNode2));
    node->val =val;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
