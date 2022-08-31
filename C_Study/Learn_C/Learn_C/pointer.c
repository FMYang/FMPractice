//
//  pointer.c
//  Learn_C
//
//  Created by yfm on 2022/8/16.
//

#include "pointer.h"

// 交换两个值
void interchanger(int *u, int *v) {
    int temp;
    temp = *u;
    *u = *v;
    *v = temp;
}

void pointer_example1(void) {
    int a = 5, b = 10;
    interchanger(&a, &b);
    printf("a = %d, b = %d \n", a, b);
}

void pointer_example(void) {
    printf("============= 指针 ==============\n");
    pointer_example1();
    printf("============= End ==============\n\n");
}
