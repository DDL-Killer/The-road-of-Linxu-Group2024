#include <stdio.h>

#define MAX_DIGITS 200  // 假设阶乘的结果不会超过200位

// 大整数加法：将num加到res上
void add_large_numbers(int *res, int *num, int len) {
    int carry = 0;  // 初始化进位
    for (int i = 0; i < len || carry; i++) {
        if (i == len) {
            res[i] = num[i] + carry;  // 当num的长度比res大时，扩展res
            len++;
        } else {
            res[i] += num[i] + carry;  // 每一位加上num和进位
        }
        carry = res[i] / 10;  // 计算进位
        res[i] %= 10;  // 保留当前位
    }
}

// 计算n!并保存在result数组中
void factorial(int n, int *result) {
    result[0] = 1;  // 初始化结果为1
    int len = 1;  // 当前结果的位数

    // 计算从1到n的阶乘
    for (int i = 2; i <= n; i++) {
        int carry = 0;  // 初始化进位
        for (int j = 0; j < len; j++) {
            int temp = result[j] * i + carry;  // 计算每位乘法结果
            result[j] = temp % 10;  // 只保留当前位
            carry = temp / 10;  // 计算进位
        }

        // 处理剩余进位
        while (carry) {
            result[len++] = carry % 10;  // 将进位添加到结果数组
            carry /= 10;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int sum[MAX_DIGITS] = {0};  // 用于存储累加结果
    int fact[MAX_DIGITS] = {0}; // 用于存储每个阶乘

    // 计算1!到n!并累加
    for (int i = 1; i <= n; i++) {
        factorial(i, fact);  // 计算i!
        add_large_numbers(sum, fact, MAX_DIGITS);  // 将i!加到sum中
    }

    // 输出结果
    int i = MAX_DIGITS - 1;
    while (i >= 0 && sum[i] == 0) i--;  // 跳过前导0
    for (; i >= 0; i--) {
        printf("%d", sum[i]);  // 从最高位输出结果
    }

    return 0;
}
