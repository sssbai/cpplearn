#include <iostream>
#include "JoiningThread.h"
int main() {
    {
        // 测试默认构造函数
        JoiningThread jt;
        std::cout << "member _i is " << jt.GetIndex() << std::endl;
        // 输出为：member _i is 454532
        // 可以看到默认构造函数并不会帮我们初始化类成员变量。
    }
    {
        // 测试有参数构造
        JoiningThread jt(1);
        std::cout << "member _i is " << jt.GetIndex() << std::endl;
        // JoiningThread jt2;
        // 实现了参数构造而不实现无参构造，系统将不会为我们实现默认构造，导致无法使用默认构造生成对象

    }
    return 0;
}