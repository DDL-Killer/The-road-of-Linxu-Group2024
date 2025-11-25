#include <stdio.h>
#include <string.h>
#include <stdlib.h> // 
#include <unistd.h> // 

/**
 * * @param P 
 * @param next 
 * @param len 
 */
void get_next(const char *P, int *next, int len) {
    // k 
    // j 
    
    next[0] = 0; // P[0] 
    int k = 0;   // k 
    
    // [已修正]
    printf("--- 计算 Next 数组 ---\n");
    printf("j=0, P[0]='%c', next[0] = 0\n", P[0]);
    usleep(500000); // 

    // j 
    for (int j = 1; j < len; j++) {
        
        // --- KMP 
        // 
        // k = next[k-1] 
        while (k > 0 && P[j] != P[k]) {
            // ***[已修正]***
            printf("j=%d, P[%d]='%c' != P[%d]='%c'. k 回溯至 next[%d]=%d\n", j, P[j], k, P[k], k - 1, next[k - 1]);
            k = next[k - 1]; // 
            // ***[已修正]***
            printf("k 现在是 %d\n", k);
            usleep(800000);
        }
        
        // --- 
        if (P[j] == P[k]) {
            printf("j=%d, P[%d]='%c' == P[%d]='%c'. k++\n", j, j, P[j], k, P[k]);
            k++; // 
            usleep(500000);
        } else {
             // ***[已修正]***
             printf("j=%d, P[%d]='%c' != P[%d]='%c'. k 已经是0, 不变\n", j, P[j], k, P[k]);
             usleep(500000);
        }
        
        // --- 
        // 
        // 
        // k 
        next[j] = k;
        printf("--- next[%d] = %d\n\n", j, k);
        usleep(1000000); // 
    }
    printf("Next 数组: ");
    for(int i=0; i<len; i++) printf("%d ", next[i]);
    // ***[已修正]***
    printf("\n-------------------------\n");
    // ***[已修正]***
    printf("计算完成！按 Enter 键开始搜索...\n");
    getchar(); // 
}

/**
 * * @param S 
 * @param P 
 * @param next 
 * @param p_len 
 * @param i 
 * @param j 
 * @param status 
 */
void print_search_state(const char *S, const char *P, const int *next, int p_len, int i, int j, const char *status) {
    // 1. 
    // 
    system("clear"); 

    // ***[已修正]***
    printf("--- KMP 搜索可视化 ---\n\n");
    
    // 2. 
    // ***[已修正]***
    printf("主串 S: %s\n", S);
    
    // 3. 
    for(int k=0; k < (7 + i); k++) printf(" "); // 
    printf("i^\n"); // 

    // 4. 
    // ***[已修正]***
    printf("模式 P: ");
    for(int k=0; k < (i - j); k++) printf(" "); // 
    printf("%s\n", P);

    // 5. 
    printf("        "); // 
    for(int k=0; k < (i - j); k++) printf(" "); // 
    for(int k=0; k < j; k++) printf(" "); // 
    printf("j^\n"); // 

    // 6. 
    // ***[已修正]***
    printf("\nNext 数组: ");
    for(int k=0; k < p_len; k++) printf("%d ", next[k]);
    printf("\n");

    // 7. 
    // ***[已修正]***
    printf("\n状态: %s\n", status);
    printf("---------------------------\n");
    printf("(i=%d, j=%d)\n", i, j);
    
    usleep(900000); // 
}

/**
 * KMP 
 * @param S 
 * @param P 
 * @param next 
 * @return 
 */
int kmp_search_visual(const char *S, const char *P, const int *next) {
    int s_len = strlen(S);
    int p_len = strlen(P);
    int i = 0, j = 0;
    char status[200]; // 

    while (i < s_len) {
        
        // 
        if (S[i] == P[j]) {
            // ***[已修正]***
            sprintf(status, "匹配! S[%d]('%c') == P[%d]('%c'). i++, j++", i, S[i], j, P[j]);
            print_search_state(S, P, next, p_len, i, j, status);
            i++;
            j++;
        } 
        // 
        else if (j > 0) {
            // ***[已修正]***
            sprintf(status, "失配! S[%d]('%c') != P[%d]('%c'). j 跳转: %d -> next[%d] = %d", i, S[i], j, P[j], j, j - 1, next[j - 1]);
            print_search_state(S, P, next, p_len, i, j, status);
            j = next[j - 1]; // 
        } 
        // 
        else {
            // ***[已修正]***
            sprintf(status, "失配! S[%d]('%c') != P[%d]('%c'). j=0, i++", i, S[i], j, P[j]);
            print_search_state(S, P, next, p_len, i, j, status);
            i++;
        }
        
        // 
        if (j == p_len) {
            // ***[已修正]***
            sprintf(status, "!!! 匹配成功 !!!");
            print_search_state(S, P, next, p_len, i-1, j-1, status); // 
            // ***[已修正]***
            printf("\n按 Enter 键退出...\n");
            getchar(); // 
            return i - j;
        }
    }
    
    // ***[已修正]***
    sprintf(status, "搜索结束, 未找到模式串.");
    print_search_state(S, P, next, p_len, i, j, status);
    // ***[已修正]***
    printf("\n按 Enter 键退出...\n");
    getchar(); // 
    return -1;
}


// --- 
int main() {
    // 
    const char *S = "aababaababacaa";
    const char *P = "ababaca";
    
    int p_len = strlen(P);
    
    // 
    int *next = (int *)malloc(sizeof(int) * p_len);
    if (next == NULL) {
        // ***[已修正]***
        printf("内存分配失败\n");
        return 1;
    }
    
    // 1. 
    get_next(P, next, p_len);
    
    // 2. 
    int found_index = kmp_search_visual(S, P, next);
    
    // 3. 
    system("clear");
    if (found_index != -1) {
        // ***[已修正]***
        printf("--- 最终结果 ---\n");
        printf("在 S 中找到了 P!\n");
    } else {
        // ***[已修正]***
        printf("--- 最终结果 ---\n");
        printf("未在 S 中找到 P.\n");
    }
    // ***[已修正]***
    printf("主串 S: %s\n", S);
    // ***[已修正]***
    printf("模式 P: %s\n", P);
    if (found_index != -1) {
        // ***[已修正]***
        printf("位置: %d\n", found_index);
        for(int k=0; k < found_index; k++) printf(" ");
        printf("^\n");
        for(int k=0; k < found_index; k++) printf(" ");
        printf("%s\n", P);
    }
    
    // 
    free(next);
    
    return 0;
}