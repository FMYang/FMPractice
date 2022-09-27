//
//  CString.c
//  DataStructures_study
//
//  Created by yfm on 2022/9/22.
//

#include "CString.h"
#include <string.h>

/**
 字符串搜索算法
 
 寻找子串：
 T为非空子串。若主串S中第pos个字符之后存在与T相等的子串，
 则返回第一个这样的子串在S中位置，否则返回0
 */

// 朴素模式匹配算法
static int Index(char *S, char *T, int pos) {
    int lens = (int)strlen(S);
    int lent = (int)strlen(T);
    int i = pos; // 第i个位置下标为i
    int j = 0; // 子串开始遍历的下标
    while (i < lens && j < lent) {
        if(S[i] == T[j]) {
            ++i; // 相等，继续比较下一个字符
            ++j; // 相等，继续比较下一个字符
        } else {
            i = i - j + 1; // 不相等，跳到主串的下一个字符处比较
            j = 0; // 不相等，回到子串开始处
        }
    }
    if(j > lent-1) {
        // 找到子串了，j为子串的长度+1
        return i - lent;
    } else {
        // 未找到子串
        return -1;
    }
}

/**
 KMP算法
 
 寻找公共前后缀的长度，避免重复查找
 例如aabaa，对应的next数组为[0, 1, 0, 1, 2]
 ABCABCD，对应[0,0,0,1,2,3,0]
 解释：
 A没有前后缀，为0
 AB没有公共前后缀，为0
 ABC没有公共前后缀，为0
 ABCA公共前后缀为A，为1
 ABCAB公共前后缀为AB，为2
 ABCABC公共前后缀为ABC，为3
 ABCABC没有公共前后缀，为0
 
 next数组存放的是，前缀子串和后缀子串相等的最大子串在前缀子串的最后一个字符的位置
 例如：ABCABC，next[5]=3，表示字符C在前缀和后缀相等的最大子串ABC的最有字符C的位置
 */
static void KMP_GetNext(char *T, int next[]) {
    int lent = (int)strlen(T);
    next[0] = 0;
    int i = 1;
    int j = 0;
    while (i < lent) {
        if(T[i] == T[j]) {
            ++j;
            next[i] = j;
            ++i;
        } else {
            if(j == 0) {
                next[i] = 0;
                ++i;
            } else {
                /*
                 回到匹配的前缀子串的最后一个字符的位置，前面的都匹配了，j值不用再回到0比较。
                 回到，已匹配的字符的前缀的最有一个字符的位置去比较。
                 */
                j = next[j - 1];
            }
        }
    }
}

static int KMP_Index(char *S, char *T, int pos) {
    int lens = (int)strlen(S);
    int lent = (int)strlen(T);
    int i = 0; // 第i个位置下标为i
    int j = 0; // 子串开始遍历的下标
    int next[lent];
    KMP_GetNext(T, next);
    while(i < lens) {
        if(T[j] == S[i]) { // 相等i和j后移
            ++i;
            ++j;
            if(j == lent) {
                // 全匹配
                return i - j;
            }
        } else if(i < lens && T[j] != S[i]) {
            // 不匹配
            if(j > 0) {
                // j值回溯
                j = next[j - 1];
            } else {
                // i值后移
                ++i;
            }
        }
    }
    return -1;
}


/**
 匹配
 ABCDABCABCABABCABCDA i = 0
 ABCABCD              j = 0

 不匹配
 ABCDABCABCABABCABCDA i = 3
 ABCABCD              j = 3
 
 不匹配
 ABCDABCABCABABCABCDA i = 3
    ABCABCD           j = next[3-1] = next[2] = 0
 
 匹配
 ABCDABCABCABABCABCDA i = 4
     ABCABCD          j = 0
 
 不匹配
 ABCDABCABCABABCABCDA i = 10
     ABCABCD          j = 6，j值回溯，j = next[6-1] = next[5] = 3
 
 匹配
 ABCDABCABCABABCABCDA i = 10
        ABCABCD       j = 3
 
 不匹配
             i
 ABCDABCABCABABCABCDA i = 12
        ABCABCD       j = 5，j值回溯，j = next[5-1] = next[4] = 2
             j

 匹配
             i
 ABCDABCABCABABCABCDA i = 12
           ABCABCD    j = 2，j值回溯，j = next[2-1] = next[1] = 0
             j
 
 不匹配
             i
 ABCDABCABCABABCABCDA i = 12
             ABCABCD  j = 0
             j
 */


// 朴素模式算法 练习
//int Index_Force(char *S, char *T) {
//    int lens = (int)strlen(S);
//    int lent = (int)strlen(T);
//    for(int i = 0; i < lens; i++) {
//        for(int j = 0; j < lent; j++) {
//            if(S[i + j] == T[j]) {
//                if(j == lent - 1) {
//                    return i;
//                }
//            } else {
//                break;
//            }
//        }
//    }
//    return -1;
//}

// 练习
//int KK_Index(char *S, char *T) {
//    int m = (int)strlen(S);
//    int n = (int)strlen(T);
//    int i = 0, j = 0;
//    int next[n];
//    KMP_GetNext(T, next);
//    while(i < m) {
//        if(S[i] == T[j]) {
//            ++i;
//            ++j;
//            if(j == n) {
//                return i - j;
//            }
//        } else if(j < n && S[i] != T[j]) {
//            if(j == 0) {
//                ++i;
//            } else {
//                j = next[j - 1];
//            }
//        }
//    }
//    return -1;
//}


void String_Example(void) {
//    char *s = "ababaaabaabb";
//    char *t = "aabaa";
    char *s = "ABCDABCABCABABCABCDA";
    char *t = "ABCABCD";
    int r = KMP_Index(s, t, 0);
//    int r = Index_Force(s, t);
//    int r = Index(s, t, 0);
    if(r == -1) {
        printf("未找到子串\n");
    } else {
        printf("子串在下标为%d的地方\n", r);
    }
}
