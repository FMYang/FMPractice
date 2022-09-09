//
//  mFunc.cpp
//  C++_Study
//
//  Created by yfm on 2022/9/9.
//

#include "mFunc.hpp"
#include <iostream>

// 1.普通函数
//int squre(int a, int b) {
//    return a * b;
//}

// 1.内联函数
inline int squre(int a, int b) {
    return a * b;
}

void func_example1(void) {
    // 常规函数调用
    squre(1, 2); // 程序将地址跳到squre的位置，执行完后返回
    squre(2, 3);
    squre(3, 4);
    
    /*
     内联函数，将函数调用部分替换为内联函数的代码执行，类似宏定义，没有跳转过程，效率更高，缺点是占用更多内存
     
     内联和宏的区别：
     宏只是简单的替换，不能按值传递（内联可以）。例如，定义宏#define squre(c) (c)*(c)，如果要计算squre(c++)的值，宏定义展开为(c++)*(c++)，内联函数的执行为c*c, c++，使用内联c只加了1次，而宏替换加了2次，所以内联比宏更灵活。
     */
//    1*2;
//    2*3;
//    3*4;
}

/**
 2.引用变量
 
 C和C++使用&表示变量的地址，C++给&符号赋予了另一个含义，将其用来声明引用。
 */
void func_example2(void) {
    using namespace std;
    int rates = 100;
    // randents是rates的引用，&表示引用类型，randents和rates指向相同的内存单元
    int &randents = rates;
    cout << "rate = " << rates << endl;
    cout << "randents = " << randents << endl;
    
    cout << "rate address = " << &rates;
    cout << ", randents address = " << &randents << endl;
    
    /**
     引用和指针的区别：
     1.引用必须在声明时初始化，不能通过赋值来设置；
     2.引用一旦与变量关联起来，就无法修改；
     引用更接近const指针。
     */
}

// 3.按引用传递参数
void func_example3(void) {
    
}

// 4.默认参数
void func_example4(void) {
    
}

// 5.函数重载
void func_example5(void) {
    
}

// 6.函数模版
void func_example6(void) {
    
}

void func_example(void) {
//    func_example1();
    func_example2();
}
