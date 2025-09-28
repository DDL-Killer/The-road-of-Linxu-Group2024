#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "linked_list.c"
//栈是一种遵循先入后出逻辑的线性数据结构

//栈的常用操作
//我们以常见的push()、pop()、peek()
//push() 元素入栈 O（1）
//pop() 栈顶元素出栈 O（1）
//peek() 访问栈顶元素 O（1）

//基于链表的实现
//将链表的头节点视为栈顶，尾节点视为栈底

//基于链表实现的栈
typedef struct{
    ListNode *top;  //将头节点作为栈顶
    int size;  //栈的长度
}LinkedListStack;

//构造函数
LinkedListStack *newLinkedListStack(){
    LinkedListStack *s = malloc(sizeof(LinkedListStack));
    s -> top = NULL;
    s -> size = 0;
    return s;
}

//析构函数
void delLinkedListStack(LinkedListStack *s){
    while(s->top){
        ListNode *n = s->top->next;
        free(s->top);
        s->top = n;
    }
    free(s);
}

//获取栈的长度
int size(LinkedListStack *s){
    return s->size;
}

//判断栈是否为空
bool isEmpty(LinkedListStack *s){
    return s->size == 0;
}

//入栈
void push(LinkedListStack *s,int num){
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->next = s->top;  //让结点跟为原有栈顶链接
    node->val = num;  //把栈的值给结点值
    s->top = node;  //让这个入栈的链表作为栈顶
    s->size++;
}

//访问栈顶元素
int peek(LinkedListStack *s){
    if(s->size == 0){
        printf("NULL");
        return __INT_MAX__;
    }
    return s->top->val;
}

//出栈
int pop(LinkedListStack *s){
    int val = peek(s);
    ListNode *tmp = s->top;
    s->top = s->top->next;
    free(tmp);
    s->size--;
    return val;
}

//----------------------------------

//基于数组实现的栈
typedef struct{
    int *data;
    int size;
}ArrayStack;

//构造函数
ArrayStack *newArrayStack(){
    ArrayStack *stack = malloc(sizeof(ArrayStack));
    stack->data = malloc(sizeof(int)*__INT_MAX__);
    stack->size = 0;
    return stack;
}

//析构函数
void delArrayStack(ArrayStack *stack){
    free(stack->data);
    free(stack);
}

//获取栈的长度
int size(ArrayStack *stack){
    return stack->size;
}

//判断栈是否为空
bool isEmpty(ArrayStack *stack){
    return stack->size == 0;
}

//入栈
void push(ArrayStack *stack,int num){
    if(stack->size == __INT_MAX__){
        printf("FULL");
        return 0;
    }
    stack->data[stack->size] = num;
    stack->size++;
}

//访问栈顶元素
int peek(ArrayStack *stack){
    if(stack->size == 0){
        printf("NULL");
        return __INT_MAX__;
    }
    return stack->data[stack->size-1];
}

//出栈
int pop(ArrayStack *stack){
    int val = peek(stack);
    stack->size--;
    return val;
}