#include<stdio.h>
#include<stdlib.h>


//初始化数组
int main(){
    int arr[5]= {0};
    int nums[5]={1,3,2,4,2};
}

//访问元素
int randomAccess(int* nums,int size){
    int radomIndex = rand()%size;
    int radomNum = nums[radomIndex];
    return radomNum;
}

//在数组的索引index处插入元素num
void insert(int *nums,int size,int num,int index){
    for(int i = size - 1;i>index;i--){
        nums[i]=nums[i-1];
    }
    nums[index] = num;
}

//删除元素
void removeItem(int* nums,int size,int index){
    for(int i = index; i <size -1;i++){
        nums[i]=nums[i+1];
    }
}

//遍历数组
void traverse(int* nums,int size){
    int count = 0;
    for(int i = 0;i<size;i++){
        count+=nums[i];
    }
}

//查找元素
int find(int* nums,int size,int target){
    for(int i = 0;i<size;i++){
        if(nums[i] == target){
            return i;
        }
    }
    return -1;
}

//扩容数组
int *extend(int *nums,int size,int enlarge){
    int* res = (int *)malloc(sizeof(int)*(size+enlarge));
    for(int i = 0;i<size;i++){
        res[i] = nums[i];
    }
    for(int i = size;i<size+enlarge;i++){
        res[i] = 0;
    }
    return res;
}