//
//  CString.c
//  DataStructures_study
//
//  Created by yfm on 2022/9/22.
//

#include "CString.h"
#include <string.h>

/**
 寻找子串：
 
 T为非空子串。若主串S中第pos个字符之后存在与T相等的子串，
 则返回第一个这样的子串在S中位置，否则返回0
 */

// 朴素模式匹配算法
int Index(char *S, char *T, int pos) {
    int lens = (int)strlen(S);
    int lent = (int)strlen(T);
    int i = pos; // 第i个位置下标为i
    int j = 0; // 子串开始遍历的下标
    while (i <= lens && j <= lent) {
        if(S[i] == T[j]) {
            ++i; // 相等，继续比较下一个字符
            ++j; // 相等，继续比较下一个字符
        } else {
            i = i - j + 1; // 不相等，跳到主串的下一个字符处比较
            j = 0; // 不相等，回到子串开始处
        }
    }
    if(j > lent) {
        // 找到子串了，j为子串的长度+1
        return i - lent;
    } else {
        // 未找到子串
        return 0;
    }
}

// KMP算法

void String_Example(void) {
    char *s = "abcdef";
    char *t = "ed";
    int r = Index(s, t, 1);
    if(r == 0) {
        printf("未找到子串\n");
    } else {
        printf("子串在下标为%d的地方\n", r-1);
    }
}
