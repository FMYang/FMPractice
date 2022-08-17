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
