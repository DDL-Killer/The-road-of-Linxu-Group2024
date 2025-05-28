//递归
int recur(int n){
    if(n == 1)
       return 1;
    int res = recur(n-1);
    return n + res;
}

//尾递归
int tailRecur(int n,int res){
    if(n==0)
       return res;
    return tailRecur(n-1,res+n);
}

//斐波那契数列，求该数列的第n个数字
int fib(int n){
    if(n==1||n==2)
       return n-1;
    int res = fib(n-1)+fib(n+1);
    return res;
}

//使用迭代模拟递归
int forLoopRecur(int n){
    int stack[1000];//借助一个大数组来模拟栈
    int top = -1;//栈顶索引
    int res = 0;
    //递：递归调用
    for(int i = n;i>0;i--){
        stack[1+top++] = i;  //通过“入栈操作”模拟“递”
    }
    //归：返回结果
    while(top>=0){
        res+=stack[top--];
    }
    return res;
}