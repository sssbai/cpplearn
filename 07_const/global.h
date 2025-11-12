//
// Created by 柏帅 on 2025/11/12.
//

#ifndef INC_07_CONST_GLOBAL_H
#define INC_07_CONST_GLOBAL_H
// const int 默认内部链接，即仅在当前文件可见
// 这里是定义
const int bufSize1 = 100;
//extern const int 外部链接，在所有文件可见
// 这里是声明
extern const int bufSize2;
void PrintBufAddress();
// 声明一个返回字面量的函数
extern int GetSize();

// define a inline constexpr function

inline constexpr int GetSizeConst() {
    return 10;
}
#endif //INC_07_CONST_GLOBAL_H