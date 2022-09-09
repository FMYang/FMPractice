//
//  array.c
//  Learn_C
//
//  Created by yfm on 2022/8/16.
//

#include "array.h"
#define MONTHS 12

/** 初始化数组并赋值 */
void array_example1(void) {
    int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int index = 0; index < MONTHS; index++) {
        printf("Month %2d has %2d days.\n", index + 1, days[index]);
    }
}

/** 数组声明和初始化分开 */
void array_example2(void) {
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
int array_sum(int *arr, int n) {
    int total = 0;
    for(int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

/** 使用指针形参 */
int array_sump(int *start, int *end) {
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

void array_example3(void) {
    int arr[10] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 2};
//    int total = array_sum(arr, 10);
    int total = array_sump(arr, arr + 10); // 使用指针形参
    printf("The total num is %d.\n", total);
    printf("The size of arr is %zd bytes.\n", sizeof(arr));
}

void array_example4(void) {
    int data[2] = { 10, 11 };
    int *ptr = data; // 把一个地址赋值给指针
    int *address = &data[0]; // 把一个地址赋值给指针
    for(int i=0; i<2; i++) {
        // 用指针遍历素组元素，三种方式等价
        printf("element = %d\n", *(data+i));
        printf("element = %d\n", *(ptr+i));
        printf("element = %d\n", *(address+i));
    }
}

/**
 指针和多维数组
 
 数组名data是数组首元素的地址，data的首元素是一个内含两个int值的数组，所以data是这个内含两个值的数组的地址。
 data是数组首元素的地址，所以data和&data[0]的值相同。而data[0]本身是个内含两个整数的数组，所以data[0]的值
 和它首元素（一个整数）的地址（即&data[0][0]）相同。简言之，data[0]是一个占用一个int大小的对象的地址，
 而data是一个占用两个int大小对象的地址。由于这个整数和内含两个整数的数组都开始于同一个地址，所以data和data[0]的值相同。
 
 因为data占用两个int大小，而data[0]指向的对象只占用一个int大小，因此data + 1和data[0]+1的值不同。
 */
void array_example5(void) {
    int data[4][2] = { 0 };
    printf("data %p &data[0] %p, data[0][0] %p\n", data, data[0], &data[0][0]);
}

///
void array_example(void) {
    printf("============= 数组 ==============\n");
//    array_example1();
//    array_example2();
//    array_example3();
//    array_example4();
    array_example5();
    printf("============= End ==============\n\n");
}
