#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int aa[n][n];  // 使用 n × n 的数组

    // 初始化数组为0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aa[i][j] = 0;
        }
    }

    int x = 0, y = 0, count = 1;

    // 通过不断改变方向来进行填充，方向依次为右、下、左、上
    while (count <= n * n) {
        // 向右填充
        while (y < n && aa[x][y] == 0) {
            aa[x][y] = count++;
            y++;
        }
        y--; // 回退到上一列，避免越界
        x++; // 准备向下

        // 向下填充
        while (x < n && aa[x][y] == 0) {
            aa[x][y] = count++;
            x++;
        }
        x--; // 回退到上一行，避免越界
        y--; // 准备向左

        // 向左填充
        while (y >= 0 && aa[x][y] == 0) {
            aa[x][y] = count++;
            y--;
        }
        y++; // 回退到上一列，避免越界
        x--; // 准备向上

        // 向上填充
        while (x >= 0 && aa[x][y] == 0) {
            aa[x][y] = count++;
            x--;
        }
        x++; // 回退到下一行，避免越界
        y++; // 准备向右
    }

    // 输出结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", aa[i][j]);
        }
        printf("\n");
    }

    return 0;
}
