//队列是一种遵循先入先出规则的线性数据结构，顾名思义，队列模拟了排队现象，新来的人不断加入队列尾部，而位于队列头部的人逐个离开

//我们将队列头部称为“队首”，尾部称为“队尾”，将把元素加入队尾的操作称为“入队”，删除队首元素的操作称为“出队”

//队列的常见操作有：
//push  元素入队，将元素添加至队尾  O（1）
//pop  队首元素出队  O（1）
//peek  访问队首元素  O（1）

//用链表实现队列
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>
#include "linked_list.c"

typedef struct{
    ListNode *front,*rear;
    int queSize;
} LinkedListQueue;

//构造函数
LinkedListQueue *newLinkedListQueue(){
    LinkedListQueue *queue = (LinkedListQueue *)malloc(sizeof(LinkedListQueue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->queSize = 0;
    return queue;
}

//析构函数
void delLinkedListQueue(LinkedListQueue *queue){
    while(queue->front != NULL){
        ListNode *tmp = queue->front;
        queue->front = queue->front->next;
        free(tmp);
    }
    free(queue); // 释放队列结构体本身
}

//获取队列的长度
int size(LinkedListQueue *queue){
    return queue->queSize;
}

//判断队列是否为空
bool empty(LinkedListQueue *queue){
    return (queue->queSize == 0);
}

//入队
void push(LinkedListQueue *queue,int num){
    ListNode *node = newListNode(num);
    if(queue->front == NULL){
        queue->front = node;
        queue->rear = node;
    }else{
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->queSize++;
}

//访问队首元素
int peek(LinkedListQueue *queue){
    assert(queue->queSize && queue->front);
    return queue->front->val;
}

//出队
int pop(LinkedListQueue *queue){
    int num = peek(queue);
    ListNode *tmp = queue->front;
    queue->front = queue->front->next;
    free(tmp);
    queue->queSize--;
    return num;
}