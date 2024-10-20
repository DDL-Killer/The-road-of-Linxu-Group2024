#include<stdio.h>
#include<math.h>
int main(){
    int a[8];
    for(int i=0;i<8;i++){
        a[i]=(int)pow(2,i+1);
    }
    int count = 0;
    do
    {
        printf("%d ",a[count]);
        count++;
    } while (count<8);
    return 0;
}
/*#include <stdio.h>

int main() {
    int a[8];  // 创建一个包含 8 个元素的数组

    // 使用 for 循环设置数组元素的值为 2 的前 8 次幂
    for (int i = 0; i < 8; i++) {
        a[i] = 1 << i;  // 1 << i 相当于 2 的 i 次幂
    }

    int count = 0;

    // 使用 do-while 循环显示数组元素的值
    do {
        printf("%d ", a[count]);
        count++;  // 计数器递增
    } while (count < 8);  // 当 count 小于 8 时继续循环

    printf("\n");  // 换行
    return 0;
}*/

