//
//  main.c
//  Learn_C
//
//  Created by yfm on 2022/8/16.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "pointer.h"
#include "array.h"
#include "struct.h"
#include "bit.h"
#include "list.h"
#include "queue.h"
#include "tree.h"
#include "stack.h"

void up_and_down(int);

/** 计算阶乘2种方式 */
// 迭代
int f(int n) {
    int sum = 1;
    for(int i = n; i > 0; i--) {
        sum *= i;
    }
    return sum;
}

// 递归
int f1(int n) {
    if(n == 1) return 1;
    return n * f1(n - 1);
}

// 尾递归
int f2(int n, int sum) {
    if(n == 1) return sum;
    return f2(n-1, n*sum);
}

int main(int argc, const char * argv[]) {
//    up_and_down(1);
    
    pointer_example();
    array_example();
    struct_example();
    bit_example();
    list_example();
    queue_example();
    tree_example();
    stack_example();
    
    return 0;
}

// 递归
void up_and_down(int n) {
    printf("before %d: n location %p\n", n, &n);
    if(n < 4) {
        up_and_down(n+1); // 1.2.3
    }
    printf("after %d: n location %p\n", n, &n);
}
