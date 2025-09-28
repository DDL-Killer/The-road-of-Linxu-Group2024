//列表是一个抽象的数据结构，它表示元素的有序集合

//初始化列表
//通常会使用“有初始值”和“无初始值”两种初始化方法

//访问元素
//列表本质上是数组

//插入与删除元素
//相较于数组，列表的可以自由地添加与删除元素，在列表尾部添加元素的时间复杂度为O（1），但插入和删除元素的效率仍与数组相同，时间复杂度为O（n）

//遍历列表
//可以根据索引遍历，也可以直接遍历

//拼接列表
//给定一个新列表nums1，我们可以将其拼接在原列表的尾部

//排列列表
//完成列表排序后，我们便可以使用在数组类算法题中常常考查的“二分查找”和“双指针”算法

//列表实现
//1. 初始容量
//2. 数据记录，声明一个变量size,用于记录列表当前元素数量，并随着元素插入和删除实时更新
//3. 扩容机制，若插入元素时列表容量已经满了，则需要进行扩容，先根据扩容倍数创建一个更大的数组，再将当前数组的所有元素依次移动到新数组

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/*列表类*/
typedef struct{
    int *arr;//数组（存储列表元素）
    int capacity;//列表容量
    int size;//列表大小
    int extendRatio;//列表每次拓展的倍数
}Mylist;

//构造函数
Mylist *newMylist(){
    Mylist *nums = malloc(sizeof(Mylist));
    nums -> capacity = 10;
    nums -> arr = malloc(sizeof(int)*nums->capacity);
    nums -> size = 0;
    nums ->extendRatio = 2;
    return nums;
}

//析构函数
void delMyList(Mylist *nums){
    free(nums->arr);
    free(nums);
}

//获取列表长度
int capacity(Mylist *nums){
    return nums->capacity;
}

//访问元素
int get(Mylist *nums,int index){
    assert(index >= 0 && index < nums->size);
    return nums -> arr[index];
}

//更新元素
void set(Mylist *nums,int index,int num){
    assert(index >= 0 && index < nums->size);
    nums->arr[index] = num;
}

//列表扩容
void extendCapacity(Mylist *nums){
    int newCapacity = nums->capacity*nums->extendRatio;
    int *extend = (int *)malloc(sizeof(int) * newCapacity);
    int *temp = nums->arr;
    
    for(int i = 0;i<nums->size;i++){
        extend[i] = nums->arr[i];
    }

    free(temp);
    nums->arr = extend;
    nums->capacity = newCapacity;
}

//在尾部添加元素
void add(Mylist *nums,int num){
    if(nums->size == nums->capacity)
        extendCapacity(nums);
    nums->arr[nums->size] = nums;
    nums->size++;
}

//在中间插入元素
void insert(Mylist *nums,int index,int num){
    assert(index >= 0 && index < nums->size);
    if(nums->size == nums->capacity ){
        extendCapacity(nums);
    }
    for(int i = nums->size;i>index;--i){
        nums->arr[i] = nums->arr[i-1];
    }
    nums->arr[index] = num;
    nums->size++;
}

//删除元素
int removeItem(Mylist *nums,int index){
    assert(index >= 0 && index < nums->size);
    int num = nums->arr[index];
    for(int i = index;i<(nums->size)-1;i++){
        nums->arr[i] = nums->arr[i+1];
    }
    nums->size--;
    return num;
}

//将列表转换为Array用于打印
int *toArray(Mylist *nums){
    return nums->arr;
}