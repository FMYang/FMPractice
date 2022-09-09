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

/**
 函数指针
 
 函数也有地址，因为函数的机器语言实现由载入内存的代码组成。指向函数的指针中存储着函数代码的起始处地址。声明一个函数指针时，必须声明指针所指向的数据类型。声明一个函数指针时，必须声明指针指向的函数类型。为了指明函数类型，要指明函数签名。即函数的返回类型和形参类型。
 */
int compare(int a, int b) {
    return a > b;
}

// 第一个参数是一个函数指针
#define Len 10
void sort(int (*pf)(int, int), int *arr) {
    for(int i = 0; i < Len - 1; i++) {
        for(int j = 0; j < Len - 1 - i; j++) {
            if(compare(arr[j], arr[j+1])) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void pointer_example2(void) {
    int arr[10] = { 3, 2, 5, 1, 9, 8, 7, 0, 10, 11 };
    // 函数名compare指向函数的起始地址，数组名arr指向数组首元素的地址
    sort(compare, arr);
    int i = 0;
    while(i<10) {
        printf("%d\n",arr[i++]);
    }
}

void pointer_example(void) {
    printf("============= 指针 ==============\n");
//    pointer_example1();
    pointer_example2();
    printf("============= End ==============\n\n");
}
