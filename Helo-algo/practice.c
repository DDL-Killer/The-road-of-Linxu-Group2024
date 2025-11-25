//层序遍历

// #include<stdio.h>
// #include<stdlib.h>
// #include "binary_tree.c"

// int *levelOrder(TreeNode *root,int *size){
//     int front,rear;
//     int index,*arr;

//     TreeNode *node;
//     TreeNode **queue;

//     queue = (TreeNode **)malloc(sizeof(TreeNode) * MAX_SIZE);

//     front = rear = index = 0;
//     queue[rear++] = root;
//     arr = (int *)malloc(sizeof(int) * MAX_SIZE);

//     while(front < rear){
//         node = queue[front++];
//         arr[index++] = node->val;
//         if(node->left!=NULL){
//             queue[rear++]=node->left;
//         }
//         if(node->right!=NULL){
//             queue[rear++]=node->right;
//         }
//     }

//     *size = index;
//     arr = realloc(arr,sizeof(int) * (*size));
//     free(queue);
//     return arr;
// }

void nizhi()