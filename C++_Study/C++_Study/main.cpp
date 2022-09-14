//
//  main.cpp
//  C++_Study
//
//  Created by yfm on 2022/9/7.
//

/*
 C++头文件没有扩展名h。有些C头文件被转换为C++头文件，这些文件被重命名，去掉了扩展名h（使之成为C++风格的名称），并在文件名前面加上前缀c（表明来自c语言）。例如C++版本的math.h为cmath
 */
// 注意：iostream后面没有.h，这是C++的风格
#include <iostream>
#include "marray.hpp"
#include "mFunc.hpp"

/** 名称空间编译指令，类、函数和变量是C++编译器的标准组件，它们现在都放置在名称空间std中 */
using namespace std; // using为编译指令

int main(int argc, const char * argv[]) {
    // 不使用名称空间的话，就要想这样使用
//    std::cout << "Hello, C++ World!\n";
    // <<符号表示将右侧的信息插入输出流中，<<符号与左移运算符相同，这是一个重载的例子
    cout << "hello\n";
    // endl是一个特色的C++符号，表示重起一行，将光标移动到下一行
    cout << endl;
    cout << "new line\n";
    
//    int cars;
//    cout << "how many cars do you have." << endl;
//    cin >> cars;
//    cout << "you have " << cars << " cars." << endl;
    
    array_example();
    func_example();
    return 0;
}
