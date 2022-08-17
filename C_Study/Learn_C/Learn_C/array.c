//
//  array.c
//  Learn_C
//
//  Created by yfm on 2022/8/16.
//

#include "array.h"
#define MONTHS 12

/** 初始化数组并赋值 */
void example1(void) {
    int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int index = 0; index < MONTHS; index++) {
        printf("Month %2d has %2d days.\n", index + 1, days[index]);
    }
}

/** 数组声明和初始化分开 */
void example2(void) {
    // 声明数组（这时候就分配内存空间了）
    int events[10];
    // 通过循环和数组下标给数组元素赋值
    for(int i = 0; i < 10; i++) {
        events[i] = 2 * i;
    }
}

/**
 指针和数组
 
 下面4种写法是等价的：
 int sum(int *arr, int n) // 指针表示法
 int sum(int *, int)
 int sum(int arr[], int n) // 数组表示法
 int sum(int [], int)
 */
int sum(int *arr, int n) {
    int total = 0;
    for(int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

/** 使用指针形参 */
int sump(int *start, int *end) {
    int total = 0;
    while (start < end) {
        /**
         和++结合律从右到左，*start++与*(start++)等价
         后者更明确，推荐使用
         
         循环完后，start等于end
        */
        total += *(start++);
    }
    return total;
}

void example3(void) {
    int arr[10] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 2};
//    int total = sum(arr, 10);
    int total = sump(arr, arr + 10); // 使用指针形参
    printf("The total num is %d.\n", total);
    printf("The size of arr is %zd bytes.\n", sizeof(arr));
}

///
void array_example(void) {
//    example1();
//    example2();
    example3();
}
