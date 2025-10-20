//双向队列提供了更高的灵活性

//双向链表的常用操作：
//方法名                描述                时间复杂度
//push_first()          将元素添加队首      O(1)
//push_last()           将元素添加队尾      O(1)
//pop_first()           删除队首元素        O(1)
//pop_last()            删除队尾元素        O(1)
//peek_first()          访问队首元素        O(1)
//peek_last()           访问队尾元素        O(1)

#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>

//双向链表节点
typedef struct DoublyListNode{
    int val;
    struct DoublyListNode *next; //后驱节点
    struct DoublyListNode *prev; //前置节点
}DoublyListNode;

//构造函数
DoublyListNode *newDoublyListNode(int num){
    DoublyListNode *new = (DoublyListNode *)malloc(sizeof(DoublyListNode));
    new->val = num;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

//析构函数
void delDoublyListNode(DoublyListNode *node){
    free(node);
}

//基于双向链表实现的双向队列
typedef struct{
    DoublyListNode *front,*rear;  //头节点 front ，尾节点 rear
    int queSize;  //双向队列的长度
}LinkedListDeque;

//构造函数
LinkedListDeque *newDoublyListDeque(){
    LinkedListDeque *deque = (LinkedListDeque *)malloc(sizeof(LinkedListDeque));
    deque->front = NULL;
    deque->rear = NULL;
    deque->queSize = 0;
    return deque;
}

//析构函数
void delLinkedListDeque(LinkedListDeque *deque){
    for(int i = 0;i<deque->queSize && deque->front != NULL;i++){
        DoublyListNode *tmp = deque->front;
        deque->front = deque->front->next;
        free(tmp);
    }
    free(deque);
}

//获取队列长度
int size(LinkedListDeque *deque){
    return deque->queSize;
}

//判断队列是否为空
bool empty(LinkedListDeque *deque){
    return (deque->queSize)==0;
}

//入队
void push(LinkedListDeque *deque,int num,bool isFront){
    DoublyListNode *node = newDoublyListNode(num);
    //若链表为空，则令 front 和 rear 都指向rear
    if(empty(deque)){
        deque->front = deque->rear = node;
    }
    //队首入队操作
    else if(isFront){
        //将node添加至链表头部
        deque->front->prev = node;
        node->next = deque->front;
        deque->front = node;
    }
    //队尾入队操作
    else{
        //将node添加至链表尾部
        deque->rear->next = node;
        node->prev = deque->rear;
        deque->rear = node;
    }
    deque->queSize++;
}

//队首入队
void push_first(LinkedListDeque *deque,int num){
    push(deque,num,true);
}

//队尾入队
void push_last(LinkedListDeque *deque,int num){
    push(deque,num,false);
}

//访问队首元素
int peekFirst(LinkedListDeque *deque){
    assert(deque->queSize && deque->front);
    return deque->front->val;
}

//访问队尾元素
int peekLast(LinkedListDeque *deque){
    assert(deque->queSize && deque->rear);
    return deque->rear->val;
}

//出队
int pop(LinkedListDeque *deque,bool isFront){
    if(empty(deque))
        return -1;
    int val;
    //队首出队操作
    if(isFront){
        val = peekFirst(deque);  //暂存头节点值
        DoublyListNode *fNext = deque->front->next;
        if(fNext){
            fNext->prev = NULL;
            deque->front->next = NULL;
        }
        delDoublyListNode(deque->front);
        deque->front = fNext;  //更新头节点
    }
    //队尾出队操作
    else{
        val = peekLast(deque);  //暂存尾节点值
        DoublyListNode *rPrev = deque->rear->prev;
        if(rPrev){
            rPrev->next = NULL;
            deque->rear->prev = NULL;
        }
        delDoublyListNode(deque->rear);
        deque->rear = rPrev;  //更新尾节点
    }
    deque->queSize--;
    return val;
}

//队首出队
int pop_first(LinkedListDeque *deque){
    return pop(deque,true);
}

//队尾出队
int pop_last(LinkedListDeque *deque){
    return pop(deque,false);
}