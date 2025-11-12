//
// Created by 柏帅 on 2025/11/12.
//
#include "global.h"
#include <iostream>
// 定义 extern const int
const int bufSize2 = 10;
void PrintBufAddress() {
    std::cout << "global.cpp buf address = " << &bufSize1 << std::endl;
    std::cout << "global.cpp buf2 address = " << &bufSize2 << std::endl;
}

int GetSize() {
    return 20;
}

