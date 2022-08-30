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
//    up_and_down(1);
    
    pointer_example();
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
