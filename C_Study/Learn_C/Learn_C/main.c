//
//  main.c
//  Learn_C
//
//  Created by yfm on 2022/8/16.
//

#include <stdio.h>
#include "pointer.h"
#include "array.h"

void up_and_down(int);

int main(int argc, const char * argv[]) {
//    printf("argc = %d\n", argc);
//
//    int i=1;
//    while (i<48) {
//        printf("%d: %s\n", i, *argv);
//        argv++;
//        i++;
//    }
    
    up_and_down(1);
    
    int a = 10, b = 5;
    interchanger(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    
    array_example();
    
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
