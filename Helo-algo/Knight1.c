#include <stdio.h>
#include <stdbool.h>
#include <limits.h> 
#include <stdlib.h> 

// 根据操作系统引入不同的头文件以实现延时
#ifdef _WIN32
#include <windows.h> // Windows 平台使用 Sleep()
#else
#include <unistd.h> // Linux/macOS 平台使用 usleep()
#endif

// 定义棋盘的大小，对于标准国际象棋是 8x8
#define N 8
// 定义延时时间（毫秒），可以调整这个值来改变动画速度
#define DELAY_MS 100

// 声明棋盘，全局变量以便于递归函数访问
int chessboard[N][N];

// 封装一个跨平台的延时函数
void delay(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000); // usleep 参数是微秒
#endif
}

// 封装一个跨平台的清屏函数
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/*
 * 函数功能：检查下一步的坐标 (next_x, next_y) 是否在棋盘内且未被访问过
 * 参数：
 *   next_x: 下一步的 x 坐标
 *   next_y: 下一步的 y 坐标
 * 返回值：
 *   如果移动有效，返回 true；否则返回 false
 */
bool is_safe(int next_x, int next_y) {
    return (next_x >= 0 && next_x < N &&
            next_y >= 0 && next_y < N &&
            chessboard[next_x][next_y] == -1);
}

/*
 * 函数功能：获取 (x, y) 位置的“度”（degree），即从该点出发有多少个有效的下一步
 * 参数：
 *   x, y: 坐标
 *   move_x[], move_y[]: 移动向量
 * 返回值：
 *   有效的下一步数量
 */
int get_degree(int x, int y, int move_x[], int move_y[]) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int next_x = x + move_x[i];
        int next_y = y + move_y[i];
        if (is_safe(next_x, next_y)) {
            count++;
        }
    }
    return count;
}



//函数功能：打印解决方案（最终的棋盘）
void print_solution() {
    clear_screen(); // 打印前先清屏
    printf("马踏棋盘寻找过程 (-1 表示未走过):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (chessboard[i][j] == -1) {
                printf("%-3s ", "."); // 未走过的点用 '.' 表示，更清晰
            } else {
                printf("%-3d ", chessboard[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

/*
 * 函数功能：使用回溯法解决马踏棋盘问题的主要递归函数
 * 参数：
 *   curr_x: 马当前所在的 x 坐标
 *   curr_y: 马当前所在的 y 坐标
 *   move_count: 当前是第几步
 *   move_x[]: 马可以移动的 x 方向向量集合
 *   move_y[]: 马可以移动的 y 方向向量集合
 * 返回值：
 *   如果从当前位置出发能找到解，返回 true；否则返回 false
 */
bool solve_knight_tour_util(int curr_x, int curr_y, int move_count, int move_x[], int move_y[]) {
    // 递归的终止条件：如果已经走完了 N*N 步，说明所有格子都已访问
    if (move_count == N * N) {
        return true; // 成功找到解
    }

    // --- Warnsdorff 规则优化 ---
    // 寻找所有可走位置中，“度”最小的那个位置
    int min_degree_idx = -1;
    int min_degree = INT_MAX;
    int next_x = -1, next_y = -1;

    // 遍历8个方向，找到最优的下一步
    for (int i = 0; i < 8; i++) {
        int temp_x = curr_x + move_x[i];
        int temp_y = curr_y + move_y[i];

        if (is_safe(temp_x, temp_y)) {
            int degree = get_degree(temp_x, temp_y, move_x, move_y);
            if (degree < min_degree) {
                min_degree = degree;
                next_x = temp_x;
                next_y = temp_y;
            }
        }
    }

    // 如果没有可走的路了 (min_degree 没被更新过)
    if (next_x == -1) {
        return false;
    }

    // “做出选择”：移动到度最小的那个格子
    chessboard[next_x][next_y] = move_count;

    // --- 打印前进的步骤 ---
    print_solution();
    printf("第 %d 步: 从 (%d, %d) 跳到 (%d, %d) (下一个位置的可选步数: %d)\n", move_count, curr_x, curr_y, next_x, next_y, min_degree);
    delay(DELAY_MS);

    // “向前探索”：从新的位置递归
    return solve_knight_tour_util(next_x, next_y, move_count + 1, move_x, move_y);
}

// 函数功能：马踏棋盘问题的主函数，负责初始化并启动求解过程
bool solve_knight_tour() {
    // 1. 初始化棋盘
    // 将棋盘所有位置都标记为 -1，表示“未访问”
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            chessboard[i][j] = -1;
        }
    }

    // 2. 定义马的 8 种移动方式
    int move_x[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int move_y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    // 3. 设置起始点
    int start_x;
    int start_y;
    printf("设置初始位置(8x8)\n");
    printf("x的坐标为：");
    while (scanf("%d", &start_x) != 1 || start_x < 0 || start_x >= N) {
        printf("输入无效，请输入 0 到 %d 之间的整数作为 x 坐标：", N - 1);
        // 清除无效的输入缓冲区
        while (getchar() != '\n');
    }

    printf("y的坐标为：");
    while (scanf("%d", &start_y) != 1 || start_y < 0 || start_y >= N) {
        printf("输入无效，请输入 0 到 %d 之间的整数作为 y 坐标：", N - 1);
        // 清除无效的输入缓冲区
        while (getchar() != '\n');
    }

    chessboard[start_x][start_y] = 0; // 第 0 步

    // 打印初始状态
    print_solution();
    printf("从 (%d, %d) 开始寻找路径...\n", start_x, start_y);
    delay(1000); 

    // 4. 从起始点开始，尝试走第 1 步
    if (solve_knight_tour_util(start_x, start_y, 1, move_x, move_y)) {
        clear_screen();
        printf("成功找到一条骑士周游路径：\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%-3d ", chessboard[i][j]);
            }
            printf("\n");
        }
        return true;
    } else {
        printf("未找到解决方案\n");
        return false;
    }
}

// 程序入口
int main() {
    solve_knight_tour();
    return 0;
}
