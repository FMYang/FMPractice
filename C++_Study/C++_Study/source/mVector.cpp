//
//  mVector.cpp
//  C++_Study
//
//  Created by yfm on 2022/9/14.
//

/**
 模版类vector和array是数组的替代品。
 
 模版类Vector是一种动态数组。可以在运行阶段设置它的长度，可以在末尾添加新数据，在中间插入新数据。基本上它是使用new创建动态数组的替代品。实际上Vector确实使用new和delete来管理内存，但这种工作是自动完成的。
 */

#include <iostream>
#include <vector>
#include <array>

void vector_example1(void) {
    using namespace std;
    // C, original C++
    double a1[4] = { 1.2, 2.4, 3.6, 4.8 };
    // C++98 STL
    vector<double> a2(4);
    a2[0] = 1.0 / 3.0;
    a2[1] = 1.0 / 5.0;
    a2[2] = 1.0 / 7.0;
    a2[3] = 1.0 / 9.0;
    // C++11
    array<double, 4> a3 = { 3.14, 2.72, 1.62, 1.41 };
    array<double, 4> a4;
    a4 = a3;
    // use array notation
    cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
    cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
    // misdeed
//    a1[-2] = 20.2; // 越界了数组也允许
    cout << "a1[-2]: " << a1[-2] << " at " << &a1[22] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
//    a2[-1] = 2.3; // 允许
//    a2.at(-1) = 2.3; // 不允许，编译报错，使用at将在运行时捕获非法索引
}

void vector_example(void) {
    vector_example1();
}
