#include <stdio.h>
#include <ctype.h>

void print_control_char(int ch) {
    // 控制字符在 ASCII 表中从 0 到 31
    if (ch < 32) {
        // 换行符和制表符特殊处理
        if (ch == '\n') {
            printf("\\n: %d\t", ch);
        } else if (ch == '\t') {
            printf("\\t: %d\t", ch);
        } else {
            // 其他控制字符使用 ^ 表示法
            printf("^%c: %d\t", ch + 64, ch); // 比如 ^A 表示 ASCII 1
        }
    } else {
        // ASCII 127 是 DEL 字符
        if (ch == 127) {
            printf("^?: %d\t", ch);
        }
    }
}

int main() {
    int ch;          // 用于存储字符的 ASCII 值
    int count = 0;   // 用于计数，每行打印 10 个字符

    // 提示用户输入字符流
    printf("请输入字符，按 Ctrl+D (Linux/Mac) 或 Ctrl+Z (Windows) 结束输入:\n");

    // 逐个字符读取输入，直到遇到 EOF
    while ((ch = getchar()) != EOF) {
        // 如果是非打印字符（除控制字符以外），则使用控制字符表示法
        if (ch < 32 || ch == 127) {
            print_control_char(ch);
        } else {
            // 可打印字符直接打印
            printf("%c: %d\t", ch, ch);
        }

        // 每打印10个字符后换行
        count++;
        if (count % 10 == 0) {
            printf("\n");
        }
    }

    // 如果最后一行字符少于 10 个，仍然换行
    if (count % 10 != 0) {
        printf("\n");
    }

    return 0;
}
