//
//  marray.cpp
//  C++_Study
//
//  Created by yfm on 2022/9/7.
//

#include "marray.hpp"
#include <iostream>

using namespace std;

void array_example1(void) {
    short things[2] = { 0, 1 }; // 指定数组元素个数
//    short things[] = { 0, 1 }; // 不指定个数，让编译器推断个数
//    int count = sizeof(things) / sizeof(short); // 自行计算个数
    for(int i=0; i<2; i++) {
        cout << things[i] << endl;
    }
    
    // C++11特性
//    double a[2] { 1.01, 1.02 }; // 省略等号
//    int b[2] = {}; // 大括号不包含任何东西，将数组所有元素设置为0
//    int b[2] {}; // 省略等号，所有元素设置为0
    
    int i = 0;
    cout << &i << endl;
}

void array_example2(void) {
    // 动态数组
    // 使用new动态分配内存，delete删除内存
    int *a = new int [2]; // 动态分配
    for(int i=0; i<2; i++) {
        a[i] = i;
        cout << a[i] << endl;
    }
    delete [] a; // 删除占用的内存
}

void array_example(void) {
    cout << endl << "=========== array ===========\n";
//    array_example1();
    array_example2();
    cout << "===========  end  ===========\n" << endl;
}
