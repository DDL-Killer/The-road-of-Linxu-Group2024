/*
二叉树是一种非线性数据结构，代表“祖先”与“后代”之间的派生关系，体现“一分为二”的分治逻辑。与链表类似，二叉树的基本
单元是节点，每个节点包含值、左子节点引用和右子节点引用
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

#define MAX_SIZE 2048

//二叉树节点结构体
typedef struct TreeNode{
    int val;                    //节点值
    int height;                 //节点高度
    struct TreeNode *left;      //左子节点指针
    struct TreeNode *right;     //右子节点指针
}TreeNode;

//构造函数
TreeNode *newTreeNode(int val){
    TreeNode *node;
    node = (TreeNode *)malloc(sizeof(TreeNode));
    node->val = val;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/*
每个节点都有两个引用（指针），分别指向左子节点和右子节点，该节点被称为两个子节点的父节点，当给定一个二叉树的节点时，我们将
该节点的左子节点以及其下节点形成的树称为该节点的左子树，同理可得右子树
在二叉树中，除叶节点外，其他所有的节点都包含子节点和非空树
*/

/*
二叉树的常见术语：
1. 根节点：位于二叉树顶层的节点，没有父节点
2. 叶节点：没有子节点的节点，其两个指针均指向None
3. 边：连接两个节点的线段，即节点引用（指针）
4. 节点所在的层（level）：从顶层底递增，根节点所在层为1
5. 节点的度：节点的子节点数量，在二叉树中，度的取值范围为0、1、2
6. 二叉树的高度：从根节点到最远叶节点所经过的边的数量
7. 节点的深度：从根节点到该节点所经过的边的数量
8. 节点的高度：从距离该节点最远的叶节点到该节点所经过的边的数量
*/

int main(){
    //初始化二叉树
    //初始化节点
    TreeNode *n1 = newTreeNode(1);
    TreeNode *n2 = newTreeNode(2);
    TreeNode *n3 = newTreeNode(3);
    TreeNode *n4 = newTreeNode(4);
    TreeNode *n5 = newTreeNode(5);
    //构建节点之间的引用（指针）
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    //插入和删除节点
    TreeNode *P = newTreeNode(0);
    //在n1 -> n2中间插入节点 P
    n1->left = P;
    P->left = n2;
    //删除节点P
    n1->left = n2;
    //释放内存
    free(P);
}

/*
层序遍历

层序遍历从顶部到底部逐层遍历二叉树，并在每一层按照从左到右的顺序访问节点

层序遍历本质上属于广度优先遍历，也称广度优先搜索，它体现了一种“一圈一圈向外扩展”的

*/

//广度优先遍历通常借助“队列”来实现，队列遵循“先进先出”的规则

/*层序遍历*/
int *levelOrder(TreeNode *root,int *size){
    *size = 0;
    if (root == NULL) {
        // 如果根节点为空（空树），直接返回一个空的、大小为0的数组
        int *empty_arr = (int *)malloc(0);
        return empty_arr;
    }

    //辅助队列
    int front,rear;
    int index,*arr;
    TreeNode *node;
    TreeNode **queue;

    //辅助队列
    queue = (TreeNode **)malloc(sizeof(TreeNode *) * MAX_SIZE);
    //队列指针
    front = 0;rear = 0;
    //加入根节点
    queue[rear++] = root;
    //初始化一个列表，用于保存遍历序列
    //辅助数组
    arr = (int *)malloc(sizeof(int) * MAX_SIZE);
    //数组指针
    index = 0;
    while(front<rear){
        //队列出队
        node = queue[front++];
        //保存节点值
        arr[index++] = node->val;
        if(node->left != NULL){
            //左子节点入队
            queue[rear++] = node->left;
        }
        if(node->right != NULL){
            //右子节点入队
            queue[rear++] = node->right;
        }
    }

    //更新数组长度的值
    *size = index;
    arr = realloc(arr,sizeof(int) * (*size));

    //释放辅助数组空间
    free(queue);
    return arr;
}

//前序、中序、后序遍历都属于深度优先遍历

//前序：根左右
//中序：左根右
//后序：左右根

//前序遍历
void preOrderRecursive(TreeNode *root, int *arr, int *index) {
    if (root == NULL)
        return;
    // 根 -> 左 -> 右
    arr[(*index)++] = root->val; // 访问根节点
    preOrderRecursive(root->left, arr, index); // 递归遍历左子树
    preOrderRecursive(root->right, arr, index); // 递归遍历右子树
}

void preOrder(TreeNode *root,int *size){
    int *arr = (int *)malloc(sizeof(int) * MAX_SIZE);
    int index = 0;
    preOrderRecursive(root, arr, &index);

    *size = index;
    if (*size > 0) {
        arr = realloc(arr, sizeof(int) * (*size));
    } else {
        free(arr);
        arr = (int *)malloc(0); // Return an empty, valid array if tree is empty
    }
    return arr;
}

//中序遍历
void inOrderRecursive(TreeNode *root, int *arr, int *index){
    if(root == NULL)
        return;
    inOrderRecursive(root->left,arr,index);
    arr[(*index)++] = root->val;
    inOrderRecursive(root->right,arr,index);
}

void inOrder(TreeNode *root,int *size){
    int *arr = (int *)malloc(sizeof(int) * MAX_SIZE);
    int index = 0;
    inOrderRecursive(root,arr,index);
    *size = index;
    if(*size >0){
        arr = realloc(arr,sizeof(int) * (*size));
    }else{
        free(arr);
        arr = (int *)malloc(0);
    }
    return arr;
}

//后序遍历
void postOrderRecursive(TreeNode *root,int *arr,int *index){
    if(root == NULL)
        return;
    postOrderRecursive(root->left,arr,index);
    postOrderRecursive(root->right,arr,index);
    arr[(*index)++] = root->val;
}

void postOrder(TreeNode *root,int *size){
    int *arr = (int *)malloc(sizeof(int) * MAX_SIZE);
    int index = 0;
    postOrderRecursive(root,arr,index);

    *size = index;
    if((*size)>0){
        arr = realloc(arr,sizeof(int) * (*size));
    }else{
        free(arr);
        arr = (int *)malloc(0);
    }

    return arr;
}


/*
对于完美二叉树，映射关系是：若某节点的索引为i,则该节点的左字节点索引为2i+1,右子节点索引为2i+2
*/

/*
二叉搜索树:binary_search_tree
    1. 对于根节点，左子树中的所有节点的值<根节点的值<右子树所有节点的值
    2. 任意节点的左、右子树也是二叉搜索树

操作：
    1. 查找节点：给定目标节点值num,可以根据二叉搜索树的性质来查找，从二叉树的根节点root出发，循环比较节点值cur.val和num之间的关系
        * 若cur.val < num ，说明目标节点在cur的右子树中，因此执行cur = cur.right
        * 若cur.val > num , 说明目标节点在cur的左子树中，因此执行cur = cur.left
        * 若cur.val = num , 说明目标节点找到，跳出该循环并返回该节点

        时间复杂度O(log n)
*/

TreeNode *search(TreeNode *bst,int num){
    TreeNode *cur = bst;
    while(cur != NULL){
        if(cur->val < num){
            cur = cur->right;
        }else if(cur->val > num){
            cur = cur->left;
        }else{
            break;   
        }
    }
    return cur;
}


