//
//  bit.c
//  Learn_C
//
//  Created by yfm on 2022/8/31.
//

#include "bit.h"
#include <stdlib.h>
#include <stdio.h>

void bit_example1(void) {
    // 1、按位取反 (1变成0，0变成1)
    unsigned char val = 0x01;
    unsigned char x = ~val;
    // 0000 0001 按位取反 1111 1110 = fe
    printf("x = %x\n", x);
    
    // 2.按位与 (都为1是为1，否则为0)
    unsigned char x1 = (0x10 & val);
    // 0001 0000 & 0000 0001 = 00000000
    printf("x1 = %x\n", x1);
    
    // 3.按位或（有一个为1就为1，否则为0）
    unsigned char x2 = (0x10 | val);
    // 0001 0000 | 0000 0001 = 00010001
    printf("x1 = %x\n", x2);
    
    // 4.按位异或（如果两个位一个为1且不是同为1，结果为1。同为1，结果为0）
    unsigned char x3 = (0xf2 ^ 0xf1);
    // 1111 0010  ^ 1111 0001 = 00000011;
    printf("x1 = %x\n", x3);
}

void bit_example2(void) {
    // 用法1:掩码
    unsigned int val = 0x0919;
    unsigned char mask = 0xff;
    unsigned char lastByte = val & mask; // 取val的最后一个字节
    printf("最后一个字节 %x\n", lastByte);
    
    // 用法2:打开位（设置位）
    unsigned char val1 = 0x10;
    unsigned char on = 0x01;
    // 假设val1最后一位表示打开开关，0表示关，1表示开
    val1 |= on; // 0x11，最后一位变为1，其他位不变
    printf("打开最后一位 %x\n", val1);
    
    // 用法3:关闭已打开的位，或打开已关闭的位
    int val2 = 0x02;
    val2 ^= 0x0f; // 0011 -> 1100
    printf("关闭已经打开的位 %x\n", val2);
    
    // 用法4:检查位的值
    int flag = 0x11;
//    if(flag == 0x01) // 不能这样判断
    if((flag & 0x01) == 0x01) {
        // &判断第0位是否为1，常用于枚举
    }
}


void bit_example(void) {
    printf("============= 位操作 ==============\n");
    bit_example2();
    printf("============= End ==============\n\n");
}
